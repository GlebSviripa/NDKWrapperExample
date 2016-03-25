package com.simplexsolutionsinc.coresignkernelwrapper.session;

public class CSSessionResult
{
	public static int Success = 0;
	public static int ErrorInternal = 1;
	public static int ErrorNotLoggedIn = 2;
	public static int ErrorAlreadyLoggedIn = 3;
	public static int ErrorLoggedInAsAnotherUser = 4;
	public static int ErrorCantAccessStorage = 5;
	public static int ErrorCantFindUserInfo = 6;
	public static int ErrorCantSaveUserInfo = 7;
	public static int ErrorInvalidUserCredentials = 8;

}
