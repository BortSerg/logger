long MedianFilter(byte samples){
  // массив для хранения данных
  long raw[samples];
  // считываем вход и помещаем величину в ячейки массива
  for (int i = 0; i < samples; i++){
    raw[i] = ADS.ReadContinuous();
  }
  // сортируем массив по возрастанию значений в ячейках
  int temp = 0; // временная переменная

  for (int i = 0; i < samples; i++){
    for (int j = 0; j < samples - 1; j++){
      if (raw[j] > raw[j + 1]){
        temp = raw[j];
        raw[j] = raw[j + 1];
        raw[j + 1] = temp;
      }
    }
  }
  // возвращаем значение средней ячейки массива
  //Serial.println(raw[samples/2]);
  return raw[samples/2];
}
