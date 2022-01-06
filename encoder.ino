void SwitchClick(byte condition)
{
  if (condition == LOW && mem == false)
  {
    Serial.println("sw down");
    mem = true;
    menu_on = true;
    DrawMenuList0(16);
  }
  if (condition == HIGH && mem == true)
  {
    Serial.println("sw UP");
    mem = false;
  }
}

void ConditionEncoder()
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
