#include <iostream>
#include <locale>


int main() {

    setlocale(LC_ALL, "");

    std::wstring ch = L"你好世界";
    std::wstring gk = L"γειά σου κόσμος";
    std::wstring jp = L"こんにちは世界";
    std::wstring ko = L"여보세요 세계";
    std::wstring pt = L"Olá mundo!";
    std::wstring ru = L"Здравствулте мир!";

    std::wcout << L"Chinês    : " << ch << std::endl;
    std::wcout << L"Grego     : " << gk << std::endl;
    std::wcout << L"Japonês   : " << jp << std::endl;
    std::wcout << L"Coreano   : " << ko << std::endl;
    std::wcout << L"Português : " << pt << std::endl;
    std::wcout << L"Russo     : " << ru << std::endl;

}