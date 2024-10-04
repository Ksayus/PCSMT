#include "FileFind.h"


#include <windows.h>
#include <iostream>

std::string ReturnFileName;

std::string FindFilesWithExtension(const std::string& ServerCorePath, const std::string& Extension) {
    WIN32_FIND_DATA findFileData;
    HANDLE FindFile;

    // ��������ģʽ���� "*.txt"
    std::string searchpattern = ServerCorePath + "/*" + Extension;
    std::cout << searchpattern << std::endl;

    //��stringת����wstring
    std::wstring midsearchpattern(searchpattern.begin(), searchpattern.end());
    std::wcout << midsearchpattern << std::endl;

    //��wstringת����LPCWSTR
    LPCWSTR SearchPattern = midsearchpattern.c_str();
    std::wcout << SearchPattern << std::endl;

    // 
    std::cout << "test" << std::endl;
    FindFile = FindFirstFile(SearchPattern, &findFileData);
    std::cout << "test1" << std::endl;
    if (FindFile != INVALID_HANDLE_VALUE) {
        do {
            // �ҵ��ļ�����ӡ�ļ���

            std::cout << "test2" << std::endl;
            std::wcout << findFileData.cFileName << std::endl;

            std::wstring midreturnfilename = findFileData.cFileName;
            //std::wcout << midreturnfilename << std::endl;

            std::string midReturnFileName(midreturnfilename.begin(), midreturnfilename.end());
            //std::cout << midReturnFileName << std::endl;

            //ReturnFileName = streammidreturnfilename.c_str();
            ReturnFileName = midReturnFileName.c_str();
        } while (FindNextFile(FindFile, &findFileData) != 0);
        FindClose(FindFile);
    }
    else {
        std::cout << "�����ļ�ʧ�ܣ�" << std::endl;
        std::cout << "δ�ҵ�.jar�ļ���" << std::endl;
    }
    return ReturnFileName;
}
//    ʹ�÷���
//    FindFilesWithExtension(directory, extension);