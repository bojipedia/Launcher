#include "../stdafx.h"
#include ".\iolocalkorea.h"
#include "../resource.h"
#include "../util/HttpManager.h"
#include "../MainFrm.h"
#include <strsafe.h>
#include "../StringManager/Safesprintf.h"
//#include "stringmanager\iostringmanager.h"
#include "../StringManager\ioStringManager.h"


ioLocalKorea::ioLocalKorea(void)
{
}

ioLocalKorea::~ioLocalKorea(void)
{
}

ioLocalManager::LocalType ioLocalKorea::GetType()
{
	return ioLocalManager::LCT_KOREA;
}

const char * ioLocalKorea::GetTextListFileName()
{
	return "text.txt";
}

const char * ioLocalKorea::GetMemTextList()
{
	return "|EXE_CMainFrame::OnCreate_1|\r\n\r\nLost Saga is already running.\r\n\r\n     Please wait a moment.\r\n\r\n\r\n\r\n  If the game hasn't been running for a long time,\r\n\r\n   please restart and try again.|"
		"|EXE_CMainFrame::OnCreate_2|Lost Saga is currently being updated. Please wait a moment.|"
		"|EXE_CMainFrame::ParseCmdAndStart_1|Invalid argument value.\r\nPlease try again later. (%1)\r\n(Error code: 104)|"
		"|EXE_CMainFrame::ParseCmdAndStart_2|Invalid start data value.\r\nPlease try again later. (%1/%2)\r\n(Error code: 106)|"
		"|EXE_CMainFrame::SetupAndStart_1|The newly set folder name is invalid.\r\nPlease try again later. (%1)\r\n(Error code: 105)|"
		"|EXE_CSetupAndStart::SetupAndStartGame_1|The argument value has changed.\r\nPlease try again later. (%1)\r\n(Error code: 101)|"
		"|EXE_CSetupAndStart::SetupAndStartGame_2|Automatic update installation has failed.\r\nPlease try again later. (%1:%2)\r\n(Error code: 102)|"
		"|EXE_CSetupAndStart::SetupAndStartGame_3|Patch info file installation has failed.\r\nPlease try again later. (%1:%2)\r\n(Error code: 103)|"
		"|EXE_CSetupAndStart::SetupAndStartGame_4|There are no running servers or the server is congested.\r\nPlease try again later. (%1)\r\n(Error code: 107)|"
		"|EXE_ioErrorDlg::ShowErrorDlg_2|--- System Specifications ---\r\n%1\r\n\r\n--- Error Information ---\r\n%2|"
		"|EXE_SetupFolderDlg::OnBnClickedChangeFolder_1|Please select the folder where Lost Saga will be installed.|"
		"|EXE_SetupFolderDlg::OnBnClickedChangeFolder_2|The installation path is empty.\r\n\r\n     Please set it again.|"
		"|EXE_SetupFolderDlg::OnBnClickedChangeFolder_3|The installation path cannot exceed 100 characters.\r\n\r\n              Please set it again.|"
		"|EXE_SetupFolderDlg::OnBnClickedChangeFolder_4|The path is invalid and cannot be used to create a folder.\r\n\r\n       Please set it again.|"
		"|EXE_SetupFolderDlg::OnBnClickedSetup_1|Preparing to install Lost Saga. Please wait.|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_1|Blocked IP address (-1).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_2|ID or password authentication failed (-2).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_3|Incorrect ID or password (-3).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_4|Channeled member (-4).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_5|Consent for personal information sharing is required (-5).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_6|Shutdown target user (0:00 AM ~ 6:00 AM) (-6).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_7|Selective shutdown target user (-7).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_8|Server is under maintenance (-8).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_9|Blocked status, unable to connect to the game (-9).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_10|No running game servers found (-10).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_11|Full access, unable to launch the game (-11).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_12|Internal error (-12)|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_13|Internal error (-13)|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_14|No user information in the login table (-14).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_15|Undefined zone type (-15).|"
		"|EXE_ioLocalKorea::GetLoginResultPostData_16|ID or password is incorrect. Please enter again.|";

}

bool ioLocalKorea::GetNewCmdLine( IN const char *szCmd, OUT char *szNewCmd, IN int iNewCmdSize )
{
	StringCbCopy( szNewCmd, iNewCmdSize, szCmd );
	return true;
}

bool ioLocalKorea::IsRightGameServerID( const CString &rszGameServerID )
{
	return true;
}

const char * ioLocalKorea::GetRegKey()
{
	return "Software\\SP2Client\\";
}

DWORD ioLocalKorea::GetResourceIDBack()
{
	return IDB_BACK;
}

DWORD ioLocalKorea::GetResourceIDChange()
{
	return IDB_CHANGEBTN;
}

DWORD ioLocalKorea::GetResourceIDSetup()
{
	return IDB_SETUPBTN;
}

DWORD ioLocalKorea::GetResourceIDErrorBack()
{
	return IDB_ERROR_BACK;
}

DWORD ioLocalKorea::GetResourceIDErrorExit()
{
	return IDB_EXITBTN;
}

DWORD ioLocalKorea::GetResourceIDErrorSolution()
{
	return IDB_SOLUTIONBTN;
}

const char * ioLocalKorea::GetErrorSolutionURL()
{
	return "http://www.lostsaga.com/common/rgfaq.asp?errnumber=%d";
}

void ioLocalKorea::SetRegKey( const char *szReg )
{
	// ºó°ª
}

void ioLocalKorea::SetStartURL( const char *szURL )
{
	// ºó°ª
}

bool ioLocalKorea::IsLoginDlg()
{
#ifdef SRC_KOR
	return true;
#endif
	return false;
}

bool ioLocalKorea::GetLoginResultPostData( OUT char *szError, IN int iErrorSize, const char *szURL, const char *szID, const char *szPW )
{
	bool bResult = false;

	// ºó°ª
	char szData[MAX_PATH] = {0,};
	char szReturn[2048] = {0,}; 
	char szTemp[2048] = {0, };

	strcpy(szData, "username=");
	strcat(szData, szID);
	strcat(szData, "&");
	strcat(szData, "password=");
	strcat(szData, szPW);

	if(g_HttpMgr.GetResultPostData(szURL, szData, szReturn, 1024, true))
	{
		char pos[2048] =  {0, };
 		memcpy(pos, szReturn, sizeof(szReturn));
		//·Î±×ÀÎ ·Î±× °ü·Ã ½ºÅ©¸³Æ® Á¦°Å
		strtok(pos, "?");
		int iSize = strlen(pos) - 1;
		int nResult = atoi(pos + iSize);
		if(nResult == 0)
		{
			SafeSprintf( szError, sizeof( char )*MAX_PATH, STR(16));
			bResult = false;
		}
		else if(nResult == 1)
		{
			strcpy_s(szError, sizeof(szReturn), szReturn + 2 + iSize);
			bResult = true;
		}
		else if(nResult < 16)
		{
			int index = abs(nResult);
			SafeSprintf( szError, sizeof( char )*MAX_PATH, STR(index));
			bResult = false;
		}
	}

	return bResult;
}

const char * ioLocalKorea::GetFontName()
{
	return "µ¸¿ò";
}

