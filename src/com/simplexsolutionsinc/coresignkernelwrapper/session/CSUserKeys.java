package com.simplexsolutionsinc.coresignkernelwrapper.session;

public class CSUserKeys
{
	long ptr;

	public CSUserKeys()
	{
		ptr = getPtrJNI();
	}
	
	public CSUserKeys(long _ptr)
	{
		ptr = _ptr;
	}

	public CSUserKeys(String _publicKey, String _privateKey,
			String _privateKeySalt)
	{
		this();
		setPrivateKey(_privateKey);
		setPublicKey(_publicKey);
		setPrivateKeySalt(_privateKeySalt);
		
	}

	public native String getPublicKey();
	public native void setPublicKey(String key);
	
	public native String getPrivateKey();
	public native void setPrivateKey(String key);
	
	public native String getPrivateKeySalt();
	public native void setPrivateKeySalt(String salt);

	public long getPtr()
	{
		return ptr;
	}

	public native long getPtrJNI();

	public native void destroy();

	@Override
	protected void finalize() throws Throwable
	{
		
		super.finalize();
		destroy();
	}

}
