#include <OLED_I2C.h>
#include <ADS1220.h>
#include <SPI.h>

#define cs_pin 7
#define rdy_pin 6

extern uint8_t SmallFont[]; //шрифт
OLED myOLED(SDA, SCL, 8);

ADS1220 ADS;

// используемые пины
byte encPinA = 4; // первый выход энкодера
byte encPinB = 3; // второй выход энкодера
byte PinSW = 5;	  // кнопка энкодера

// переменные для хранения состояний пинов
bool encA;
bool encB;

byte display_number = 0;  // индекс скрина 0-main screen; 1-main menu screen; 2-sub menu screen
byte number_sub_menu = 0; // номер подменю

// переменные для информации о состояниях и движениях энкодера
bool prev11;			 // предыдущее состояние было 11
bool clockwise1 = true;	 // переход по часовой стрелке 1 (от 11)
bool clockwise2 = false; // переход по часовой стрелке 2 (от 00)

// изменяемое значение энкодера и указателя
byte old_value = 1;		  // прошлое значение энкодера
byte value = 1;			  // значение энкодера
byte pos_pointer = 16;	  // позиция указателя (начальное положение указателя = 16, исходя из конфигурации меню)
byte old_pos_pointer = 0; // позиция указателя до перехода в подменю
byte limit_value = 17;	  // предел значений энкодера

byte pos_settings_pointer[15][2]; // [значение value][значение pos_pointer] каждая строка массива соответствует номеру подменю (number_sub_menu -1)
bool set_settings_flag = true;	  // флаг наличия изминений в настройках

void setup()
{
	Serial.begin(115200);

	pinMode(encPinA, INPUT);
	digitalWrite(encPinA, HIGH);
	pinMode(encPinB, INPUT);
	digitalWrite(encPinB, HIGH);
	pinMode(PinSW, OUTPUT);
	digitalWrite(PinSW, HIGH);

	pinMode(cs_pin, OUTPUT);
	pinMode(rdy_pin, INPUT);

	ADS.begin(cs_pin, rdy_pin);

	InitDisplay();
}

void loop()
{
	//считывание кнопки энкодера
	SwitchClick(digitalRead(PinSW));

	// считывание состояния выходов энкодера
	encA = digitalRead(encPinA);
	encB = digitalRead(encPinB);
	ConditionEncoder(limit_value);

	if (display_number == 0)
	{
		DrawMainScreen();
	}

	if (old_value != value)
	{
		switch (display_number)
		{
		case 1:
			PosPointer();
			DrawMainMenu(pos_pointer);
			break;

		case 2:
			PosPointer();
			DrawSubMenu(number_sub_menu, pos_pointer);
			break;
		}
	}
	old_value = value;
}
