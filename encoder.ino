void SwitchClick(byte condition)
{
  if (condition == LOW && menu_on == false && sub_menu_on == false) // обработка входа в меню
  {
    value = 1;
    DrawMenuList(pos_pointer);
    Serial.println("sw down");
    delay(500);
    main_screen_on = false;
    menu_on = true;
    condition = !condition; // защита от удержания кнопки (антидребезг)
  }

  if (condition == LOW && menu_on == true && sub_menu_on == false) // обработка входа в подменю
  {
    number_sub_menu = value;
    value = 1;
    DrawSubMenu(number_sub_menu, pos_pointer);
    sub_menu_on = true;
    menu_on = false;
    condition = !condition; // защита от удержания кнопки (антидребезг)
  }

  if (condition == LOW && menu_on == false && sub_menu_on == true) // обработка выбраного значения в подменю
  {
    condition = !condition; // защита от удержания кнопки (антидребезг)
  }
}

void ConditionEncoder(byte limit)
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
