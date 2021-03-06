// vgmByteStreamHandler.h : Declaration of the CvgmByteStreamHandler

#pragma once
#include "resource.h"       // main symbols



#include "vgmcodec_i.h"
#include <gsl.h>



using namespace ATL;


// CvgmByteStreamHandler

class ATL_NO_VTABLE CvgmByteStreamHandler :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CvgmByteStreamHandler, &CLSID_vgmByteStreamHandler>,
	public IMFByteStreamHandler
{
public:
	CvgmByteStreamHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VGMBYTESTREAMHANDLER)

DECLARE_NOT_AGGREGATABLE(CvgmByteStreamHandler)

BEGIN_COM_MAP(CvgmByteStreamHandler)
	COM_INTERFACE_ENTRY(IMFByteStreamHandler)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct() noexcept
	{
		return S_OK;
	}

	void FinalRelease() noexcept
	{
	}

public:
	IFACEMETHOD(BeginCreateObject)(
		/* [in] */ IMFByteStream *pByteStream,
		/* [in] */ LPCWSTR pwszURL,
		/* [in] */ DWORD dwFlags,
		/* [in] */ IPropertyStore *pProps,
		/* [annotation][out] */
		_Outptr_opt_  IUnknown **ppIUnknownCancelCookie,
		/* [in] */ IMFAsyncCallback *pCallback,
		/* [in] */ IUnknown *punkState) noexcept;

	IFACEMETHOD(EndCreateObject)(
		/* [in] */ IMFAsyncResult *pResult,
		/* [annotation][out] */
		_Out_  MF_OBJECT_TYPE *pObjectType,
		/* [annotation][out] */
		_Outptr_  IUnknown **ppObject) noexcept;

	IFACEMETHOD(CancelObjectCreation)(
		/* [in] */ IUnknown *pIUnknownCancelCookie) noexcept;

	IFACEMETHOD(GetMaxNumberOfBytesRequiredForResolution)(
		/* [annotation][out] */
		_Out_  QWORD *pqwBytes) noexcept;

private:
	ATL::CComPtr<IMFByteStream> handleGZip(gsl::not_null<IMFByteStream*> );

};

OBJECT_ENTRY_AUTO(__uuidof(vgmByteStreamHandler), CvgmByteStreamHandler)
