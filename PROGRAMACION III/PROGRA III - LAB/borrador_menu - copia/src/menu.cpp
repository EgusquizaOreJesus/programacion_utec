/*
static void drawMenuOptions(const Menu* const menu){
    const int32_t middleWidth = GetScreenWidth() / 2;
    const int32_t middleHeight = GetScreenHeight() / 2;
    const int32_t fontSize = 24;
    const int32_t posY = middleHeight + 45;
    const int32_t posXStart = middleWidth - MeasureText("START", fontSize) / 2;
    const int32_t posXOptions = middleWidth - MeasureText("OPTIONS", fontSize) / 2;
    const int32_t posXExit = middleWidth - MeasureText("EXIT", fontSize) / 2;

    const Color startColor = (menu->option == OPT_START) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };
    const Color optionsColor = (menu->option == OPT_OPTIONS) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };
    const Color endColor = (menu->option == OPT_EXIT) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };

    DrawText("START", posXStart, posY, fontSize, startColor);
    DrawText("OPTIONS", posXOptions, posY + fontSize + 5, fontSize, optionsColor);
    DrawText("EXIT", posXExit, posY + (fontSize * 2) + 10, fontSize, endColor);
}
static void drawTitle() {
    const int32_t fontSize = 128;
    const int32_t middle = GetScreenWidth() / 2;
    const int32_t titleLen = MeasureText("MAZE", fontSize);
    const int32_t posX = middle - titleLen / 2;
    const int32_t posYBase = 20;
    const int32_t posY = 30;
    const int32_t height = 15;
    DrawRectangle(posX, posYBase + 20, titleLen, height, (Color){ 168, 159, 148, 255 });
    DrawText("MAZE", posX, posYBase + posY, fontSize, (Color){ 112, 107, 102, 255 });
    DrawRectangle(posX, posYBase + fontSize + 10, titleLen, height, (Color){ 168, 159, 148, 255 });
}
static void updateMenuOptions(Menu *const menu) {
    const int32_t min = (int32_t) OPT_START;
    const int32_t max = (int32_t) OPT_EXIT;
    if (IsKeyPressed(KEY_UP)) {
        const int32_t value = menu->option - 1;
        if (value >= min) {
            menu->option = static_cast<OptionEvent>(menu->option - 1);
        } else {
            menu->option = OPT_EXIT;
        }
    } else if (IsKeyPressed(KEY_DOWN)) {
        const int32_t value = menu->option + 1;
        if (value <= max) {
            menu->option = static_cast<OptionEvent>(menu->option + 1);
        } else {
            menu->option = OPT_START;
        }
    }
}
 */

