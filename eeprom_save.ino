void save_Config()
{
    size_t sz1 = sizeof(Config);
    for (unsigned int i = 0; i < sz1; i++)
        EEPROM.write(i, *((uint8_t *)&Config + i));

    // EEPROM.commit();  // раскоментировать для ESP8266
}

void Read_Config()
{
    size_t sz1 = sizeof(Config);
    for (int i = 0; i < sz1; i++)
    {
        uint8_t c = EEPROM.read(i);
        *((uint8_t *)&Config + i) = c;
    }
}

void RestoreSettings()
{
    if (Config.FIRST_CHECK_BYTE != 0x49) // проверка памяти настроек в EEPROM при первом запуске
    {
        Config.FIRST_CHECK_BYTE = 0x49;
        Config.ADS_SETTINGS_BYTE[0] = 0x00; // дефолтные значения регистров настройки
        Config.ADS_SETTINGS_BYTE[1] = 0x04;
        Config.ADS_SETTINGS_BYTE[2] = 0x10;
        Config.ADS_SETTINGS_BYTE[3] = 0x00;
        for (byte i = 0; i < 16; i++)
        {
            Config.POS_SETTINGS_POINTER[i][0] = i;
            Config.POS_SETTINGS_POINTER[i][1] = 1;
        }

        save_Config();
        ADS.SetDefaultSettings(); // дефолтные настройки уже заданы в самой библиотеке <ADS1220.h>
        Serial.println(F("ERROR read settings byte. Restore default values"));
    }
    else
    {
        for (byte i = 0; i < 4; i++)
        {
            ADS.WriteConfig(i, Config.ADS_SETTINGS_BYTE[i]);
        }
        Serial.println(F("Settings are loaded"));
    }
}