void InitDisplay()
{
    myOLED.begin();
    myOLED.setFont(SmallFont);
    myOLED.setBrightness(255);
    myOLED.clrScr();
}