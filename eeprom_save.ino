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
        Config.ADS_SETTINGS_BYTE[0] = default_value_reg0; // дефолтные значения регистров настройки
        Config.ADS_SETTINGS_BYTE[1] = default_value_reg1;
        Config.ADS_SETTINGS_BYTE[2] = default_value_reg2;
        Config.ADS_SETTINGS_BYTE[3] = default_value_reg3;
        for (byte i = 0; i < 16; i++)
        {
            Config.POS_SETTINGS_POINTER[i][0] = i + 1;
            Config.POS_SETTINGS_POINTER[i][1] = 16;
        }

        save_Config();
        ADS.SetDefaultSettings(); // дефолтные настройки уже заданы в самой библиотеке <ADS1220.h>
        Serial.println(F("Restore default values is complete"));
    }
    else
    {
        for (byte i = 0; i < 4; i++)
        {
            ADS.WriteConfig(i, Config.ADS_SETTINGS_BYTE[i]);
        }
        Serial.println(F("Last saved settings are loaded"));
    }
}