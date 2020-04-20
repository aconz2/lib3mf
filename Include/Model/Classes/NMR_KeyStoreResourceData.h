/*++

Copyright (C) 2019 3MF Consortium

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

Abstract:

NMR_KeyStoreResourceData.h defines the KeyStoreResourceData Class. A ResourceData is an in memory representation of the 3MF keystore resourcedata element.

--*/

#ifndef __NMR_KEYSTORERESOURCEDATA
#define __NMR_KEYSTORERESOURCEDATA

#include <map>
#include <memory>
#include <vector>
#include "Common/NMR_Types.h"
#include "Common/NMR_SecureContentTypes.h"
#include "Model/Classes/NMR_PackageResourceID.h"
#include "Model/Classes/NMR_KeyStoreCEKParams.h"
namespace NMR {
	enum eResourceDataState {
		NEW = 0,
		CLOSED,
		OPEN
	};
	class CKeyStoreResourceData: public CKeyStoreCEKParams {
		std::string m_sPath;
		static nfUint64 s_nfHandleCount;
	public:
		CKeyStoreResourceData(std::string const& path, 
			bool compression,
			eKeyStoreEncryptAlgorithm alg,
			std::vector<nfByte> const & iv,
			std::vector<nfByte> const & tag,
			std::vector<nfByte> const & aad);

		inline std::string const & getPath() const {
			return m_sPath;
		}

		void setInitVector(std::vector<nfByte> const &newIV);
		void setAuthTag(std::vector<nfByte> const & newTag);
	};
	typedef std::shared_ptr<CKeyStoreResourceData> PKeyStoreResourceData;
}

#endif
