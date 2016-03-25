package com.simplexsolutionsinc.coresignkernelwrapper;


public class CSKernelIniter
{
	static
	{
		System.loadLibrary("crystax");
		System.loadLibrary("gnustl_shared");
		
		System.loadLibrary("CoreSignKernel");
		System.loadLibrary("CoreSignKernelWrapper");

	}
	public static void init()
	{
		
	}

}
