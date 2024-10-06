#include "FileFind.h"


#include <windows.h>
#include <iostream>
#include "FilesFoldersPosition.h"

std::string ReturnFileName;

std::string FindFilesWithExtension(const std::string& ServerCorePath, const std::string& Extension) {
    std::ofstream LogFile(LogOutputPath, std::ios::out | std::ios::app);
    auto Output = [&](const std::string& text) {
        std::cout << text << std::endl;
        LogFile << text << std::endl;
        };

    WIN32_FIND_DATA findFileData;
    HANDLE FindFile;

    // ��������ģʽ���� "*.txt"
    std::string searchpattern = ServerCorePath + "/*" + Extension;
    std::cout << searchpattern << std::endl;

    //��stringת����wstring
    /*std::wstring midsearchpattern(searchpattern.begin(), searchpattern.end());
    std::wcout << midsearchpattern << std::endl;*/

    //��wstringת����LPCWSTR
    LPCSTR SearchPattern = searchpattern.c_str();
    std::wcout << SearchPattern << std::endl;

    // 
    //std::cout << "test" << std::endl;
    FindFile = FindFirstFile(SearchPattern, &findFileData);
    //std::cout << "test1" << std::endl;
    if (FindFile != INVALID_HANDLE_VALUE) {
        do {
            // �ҵ��ļ�����ӡ�ļ���

            //std::cout << "test2" << std::endl;
            std::wcout << findFileData.cFileName << std::endl;

            //std::wstring midreturnfilename = findFileData.cFileName;
            //std::wcout << midreturnfilename << std::endl;

            //std::string midReturnFileName() = findFileData.cFileName();
            //std::cout << midReturnFileName << std::endl;

            //ReturnFileName = streammidreturnfilename.c_str();
            ReturnFileName = findFileData.cFileName;
        } while (FindNextFile(FindFile, &findFileData) != 0);
        FindClose(FindFile);
    }
    else {
        Output("�����ļ�ʧ�ܣ�");
        Output("δ�ҵ�" + Extension + "�ļ���");
    }
    LogFile.close();
    return ReturnFileName;
}
//    ʹ�÷���
//    FindFilesWithExtension(directory, extension);