package com.simplexsolutionsinc.coresignkernelwrapper.documents;

public abstract class CSDocumentFilter {

	public static final int empty = 0;
	public static final int ByName = 1;
	public static final int BySigner = 2;
	
	
	

	//kernel methods
	
	public abstract int getType();

}
