void SwitchClick(byte condition) // обработка нажатий на энкодер
{
  if (condition == LOW && menu_on == false && sub_menu_on == false) // обработка входа в меню
  {
    value = 1; // сброс позиции указателя вменю

    old_value += value; //имитация вращения энкодера

    menu_on = true;
    main_screen_on = false;

    delay(200);
    condition = !condition;
  }

  if (condition == LOW && menu_on == true && sub_menu_on == false) // обработка из меню для входа в подменю
  {
    pos_pointer = 16; // сброс позиции указателя

    number_sub_menu = value; // номер подменю = номеру пункта в основном меню
    value = 1;               // сброс значений энкодера для отсчета с первого пункта
    old_value += value;      //имитация вращения энкодера

    menu_on = false;
    sub_menu_on = true;

    delay(200);
    condition = !condition;
  }

  if (condition == LOW && menu_on == false && sub_menu_on == true) // обработка выбраного значения в подменю
  {
    condition = !condition;
    if ((number_sub_menu == 1 || number_sub_menu == 4 || number_sub_menu == 5 || number_sub_menu == 6 || number_sub_menu == 10 || number_sub_menu == 13) && value == 3)
    {
      sub_menu_on = false;
      menu_on = true;
      pos_pointer = 16;
      value = 1;
      delay(200);
    }
    if ((number_sub_menu == 8 || number_sub_menu == 14 || number_sub_menu == 15) && value == 8)
    {
      sub_menu_on = false;
      menu_on = true;
      pos_pointer = 16;
      value = 1;
      delay(200);
    }
    if ((number_sub_menu == 3 && value == 18) || (number_sub_menu == 7 && value == 4) || ((number_sub_menu == 2 || number_sub_menu == 9) && value == 9))
    {
      sub_menu_on = false;
      menu_on = true;
      pos_pointer = 16;
      value = 1;
      delay(200);
    }
    if ((number_sub_menu == 11 || number_sub_menu == 12) && value == 5)
    {
      sub_menu_on = false;
      menu_on = true;
      pos_pointer = 16;
      value = 1;
      delay(200);
    }
  }
}

void PosPointer() // передвижение  по меню указателя
{
  if (value > old_value)
  {
    pos_pointer += 10;
    if ((value == 6 || value == 11 || value == 16) && pos_pointer > 56)
    {
      pos_pointer = 16;
    }
  }

  if (value < old_value)
  {
    pos_pointer -= 10;
    if ((value == 5 || value == 10 || value == 15) && pos_pointer < 16)
    {
      pos_pointer = 56;
    }
    if (value == 1 && pos_pointer < 16)
    {
      pos_pointer = 16;
    }
  }
}

void ConditionEncoder(byte limit) // обработка поворотов экнокдера
{
  // если в состояние 11 пришли не из 11
  // и 2 раза детектировалось движение
  // в одну и ту же сторону, то соответствующим
  // образом изменяем значение переменной

  if ((encA) && (encB) && (!prev11))
  {
    if ((clockwise1) && (clockwise2))
    {
      value++;
    }
    if ((!clockwise1) && (!clockwise2))
    {
      value--;
    }
    prev11 = true;
    if (value > limit)
    {
      value = limit;
    }
    if (value < 1)
    {
      value = 1;
    }
    Serial.println(value);
  }

  // детектирование направления первого перехода (от 11)

  else if ((!encA) && (encB) && (prev11))
  {
    clockwise1 = true;
    prev11 = false;
  }
  else if ((encA) && (!encB) && (prev11))
  {
    clockwise1 = false;
    prev11 = false;
  }

  // детектирование направления второго перехода (от 00)

  else if ((!encA) && (encB) && (!prev11))
  {
    clockwise2 = false;
  }
  else if ((encA) && (!encB) && (!prev11))
  {
    clockwise2 = true;
  }
}
