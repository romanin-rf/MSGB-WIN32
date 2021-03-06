#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

int main(int argc, char *argv[]){
	setlocale(0, "");

	int version_msgb_api = 1140321;
	string version_msg = "0.1.140321-beta";

	string MessageBoxTitle;
	string MessageBoxText;

	int MessageBoxTypeNumber;

	if((argc >= 5) and (string(argv[1]) == "-msg")){
		MessageBoxTitle = argv[2];
		MessageBoxText = argv[3];
		MessageBoxTypeNumber = stoi(argv[4]);
	}else{
		if(argc > 1){
			if(string(argv[1]) == "-h"){
				MessageBoxTitle = "MSGBox - Help";
				MessageBoxText = "-------------------------------------------------------------------\nmsgb.exe -msg \"Название MSGBox\" \"Текст внутри MSGBox\" N\n-------------------------------------------------------------------\nN - это целочисленое значение, которого это типа MSGBox. Чтобы узнать подробнее msgb.exe -hn\n-------------------------------------------------------------------\nАвтор: Роман Слабицкий\nВерсия: " + version_msg + "\n-------------------------------------------------------------------";
				MessageBoxTypeNumber = 32;
			}else{
				if(string(argv[1]) == "-hn"){
					MessageBoxTitle = "MSGBox - Help-N";
					MessageBoxText = "-------------------------------------------------------------------\nЕсть несколько типов MSGBox (N):\n+ 0. окно с кнопкой \"ОК\";\n+ 1. окно с кнопкой \"ОК\" и \"ОТМЕНА\";\n+ 2. окно с кнопкой \"ПРЕРВАТЬ\" и \"ПОВТОР\" и \"ПРОПУСТИТЬ\";\n+ 3. окно с кнопкой \"ДА\" и \"НЕТ\" и \"ОТМЕНА\";\n+ 4. окно с кнопкой \"ДА\" и \"НЕТ\";\n+ 5. окно с кнопкой \"ПОВТОР\" и \"ОТМЕНА\";\n+ 6. окно с кнопкой \"ОТМЕНА\" и \"ПОВТОРИТЬ\" и \"ПРОДОЛЖИТЬ\";\n-------------------------------------------------------------------\nДля облегчения воспринимайте следующих текст как точку осчёта:\nc 0 - это окно без значка;\nс 16 - это окно со значком ошибки;\nc 32 - это окно со значком вопроса;\nc 48 - это окно со значком предупреждения;\nc 64 - это окно со значком оповещения;\n-------------------------------------------------------------------\nПример:\n16 + 4 = 20\n// Вводим в консоль\n> msgb.exe -msg \"Title\" \"Text\" 20\nИ вам выведеться окно ОШИКБИ с кнопками \"ДА\" и \"НЕТ\";\n-------------------------------------------------------------------";
					MessageBoxTypeNumber = 32;
				}else{
					MessageBoxTitle = "MSGBox - Help";
					MessageBoxText = "-------------------------------------------------------------------\nmsgb.exe -msg \"Название MSGBox\" \"Текст внутри MSGBox\" N\n-------------------------------------------------------------------\nN - это целочисленое значение, которого это типа MSGBox. Чтобы узнать подробнее msgb.exe -hn\n-------------------------------------------------------------------\nАвтор: Роман Слабицкий\nВерсия: " + version_msg + "\n-------------------------------------------------------------------";
					MessageBoxTypeNumber = 32;
				};
			};
		}else{
			MessageBoxTitle = "MSGBox - Help";
			MessageBoxText = "-------------------------------------------------------------------\nmsgb.exe -msg \"Название MSGBox\" \"Текст внутри MSGBox\" N\n-------------------------------------------------------------------\nN - это целочисленое значение, которого это типа MSGBox. Чтобы узнать подробнее msgb.exe -hn\n-------------------------------------------------------------------\nАвтор: Роман Слабицкий\nВерсия: " + version_msg + "\n-------------------------------------------------------------------";
			MessageBoxTypeNumber = 32;
		};
	};
	int press_button_number = MessageBox(NULL, MessageBoxText.c_str(), MessageBoxTitle.c_str(), MessageBoxTypeNumber);
	cout << press_button_number;
}
