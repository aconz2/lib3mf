/*++

Copyright (C) 2018 3MF Consortium (Original Author)

All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Abstract: This is a stub class definition of CLib3MFSlice

*/

#include "lib3mf_slice.hpp"
#include "lib3mf_interfaceexception.hpp"

// Include custom headers here.


using namespace Lib3MF::Impl;

/*************************************************************************************************************************
 Class definition of CLib3MFSlice 
**************************************************************************************************************************/

CLib3MFSlice::CLib3MFSlice(NMR::PSlice pSlice)
	:m_pSlice(pSlice)
{
	
}

void CLib3MFSlice::SetVertices (const Lib3MF_uint64 nVerticesBufferSize, const sLib3MFPosition2D * pVerticesBuffer)
{
	m_pSlice->Clear();
	for (Lib3MF_uint64 index = 0; index < nVerticesBufferSize; index++) {
		m_pSlice->addVertex(pVerticesBuffer->m_coordinates[0], pVerticesBuffer->m_coordinates[1]);
		pVerticesBuffer++;
	}
}

void CLib3MFSlice::GetVertices (Lib3MF_uint64 nVerticesBufferSize, Lib3MF_uint64* pVerticesNeededCount, sLib3MFPosition2D * pVerticesBuffer)
{
	Lib3MF_uint64 vertexCount = m_pSlice->getVertexCount();
	if (pVerticesNeededCount)
		*pVerticesNeededCount = vertexCount;

	if (nVerticesBufferSize >= vertexCount && pVerticesBuffer)
	{
		for (Lib3MF_uint32 i = 0; i < vertexCount; i++)
		{
			const NMR::SLICENODE* node = m_pSlice->getNode(i);
			pVerticesBuffer[i].m_coordinates[0] = node->m_position.m_fields[0];
			pVerticesBuffer[i].m_coordinates[1] = node->m_position.m_fields[1];
		}
	}
}

Lib3MF_uint64 CLib3MFSlice::GetVertexCount ()
{
	return m_pSlice->getVertexCount();
}

Lib3MF_uint64 CLib3MFSlice::GetPolygonCount ()
{
	return m_pSlice->getPolygonCount();
}

void CLib3MFSlice::SetPolygonIndices (const Lib3MF_uint64 nIndex, const Lib3MF_uint64 nIndicesBufferSize, const Lib3MF_uint32 * pIndicesBuffer)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFSlice::GetPolygonIndices (const Lib3MF_uint64 nIndex, Lib3MF_uint64 nIndicesBufferSize, Lib3MF_uint64* pIndicesNeededCount, Lib3MF_uint32 * pIndicesBuffer)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

void CLib3MFSlice::GetPolygonIndexCount (const Lib3MF_uint64 nIndex, Lib3MF_uint64 & nCount)
{
	throw ELib3MFInterfaceException (LIB3MF_ERROR_NOTIMPLEMENTED);
}

double CLib3MFSlice::GetZTop()
{
	throw ELib3MFInterfaceException(LIB3MF_ERROR_NOTIMPLEMENTED);
}
