#include "keyboard.h"
#include "string.h"
#include "stdlib.h"

    bool isLeftShiftPressed;
    bool isRightShiftPressed;


void super_idol()
{
    GlobalRenderer->Print("Super idol de xiaorong");
    GlobalRenderer->Next();
    GlobalRenderer->Print("dou mei ni de tian");
    GlobalRenderer->Next();
    GlobalRenderer->Print("ba yue zhengwu de yangguang");
    GlobalRenderer->Next();
    GlobalRenderer->Print("dou mei ni yaoyan");
    GlobalRenderer->Next();
    GlobalRenderer->Print("re'ai bai ling wu du de ni");
    GlobalRenderer->Next();
    GlobalRenderer->Print("di di qingchun de zhengliushui");
    GlobalRenderer->Next();
    currentInput = 0;
}

void help()
{
    GlobalRenderer->Print("NO HELP FOR U");
    GlobalRenderer->Next();
    currentInput = 0;
}

void prinln(const char* str)
{
    GlobalRenderer->Print(str);
    currentInput = 0;
    GlobalRenderer->Next();
}

void Help()
{
    prinln("hello - says Hello!");
    prinln("about - shows info about the system");
    prinln("zuim - print the zuimOS logo");
    prinln("song - sing a song for Mark");
    prinln("license - shows the system's license (The Unlicense)");
    prinln("green or white - change the system color");
    prinln("Math:");
    prinln("    add[op1,op2]");
    prinln("    sub[op1,op2]");
    prinln("    mul[op1,op2]");
    prinln("    div[op1,op2]");
    currentInput = 0;

}

void changeGreen()
{
    GlobalRenderer->ChangeColour(0x0000FF00);
}

void changeWhite()
{
    GlobalRenderer->ChangeColour(0xFFFFFFFF);
}

void license()
{
    prinln("This is free and unencumbered software released into the public domain.");
    prinln("Anyone is free to copy, modify, publish, use, compile, sell, or distribute");
    prinln("this software, either in source code form or as a compiled binary, for any");
    prinln("purpose, commercial or non-commercial, and by any means.");
    prinln("");
    prinln("In jurisdictions that recognize copyright laws, the author or authors of this");
    prinln("software dedicate any and all copyright interest in the software to the public");
    prinln("domain. We make this dedication for the benefit of the public at large and to");
    prinln("the detriment of our heirs and successors. We intend this dedication to be an");
    prinln("overt act of relinquishment in perpetuity of all present and future rights to");
    prinln("this software under copyright law.");
    prinln("");
    prinln("THE SOFTWARE IS PROVIDED \"AS IS\",");
    prinln("WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO");
    prinln("THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND");
    prinln("NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES");
    prinln("OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING");
    prinln("FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN");
    prinln("THE SOFTWARE.");
    prinln("");
    prinln("For more information, please refer to <http://unlicense.org/>");
}

void about()
{
    prinln("ZuimOS 1.0 - 2022");
    prinln("Devs:");
    prinln("    Tallys Assis");
    prinln("    Eros Rodrigues");
    prinln("    Bryan Jonathan");
    prinln("    Daniel Soares");
    prinln("    João Gabriel");
    prinln("Based on PonchOS, from Poncho");
    currentInput = 0;
}

void hello()
{
    prinln("Hello");
    prinln(inputBuffer);
    currentInput = 0;
}

void zuim()
{
    GlobalRenderer->Print(" _____     _            ___  ____  ");
    GlobalRenderer->Next();
    GlobalRenderer->Print("|__  /   _(_)_ __ ___  / _ \\/ ___| ");
    GlobalRenderer->Next();
    GlobalRenderer->Print("  / / | | | | '_ ` _ \\| | | \\___ \\ ");
    GlobalRenderer->Next();
    GlobalRenderer->Print(" / /| |_| | | | | | | | |_| |___) |");
    GlobalRenderer->Next();
    GlobalRenderer->Print("/____\\__,_|_|_| |_| |_|\\___/|____/ ");
    GlobalRenderer->Next();
    currentInput = 0;
}

void execute()
{
    if(strcmp(inputBuffer, "zuim") == 0)
    {
        zuim();
    }
    else if(strcmp(inputBuffer, "clear") == 0)
    {
        GlobalRenderer->Clear();        
    }
    else if(strcmp(inputBuffer, "green") == 0)
    {
        changeGreen();      
    }
    else if(strcmp(inputBuffer, "white") == 0)
    {
        changeWhite();      
    }
    else if(strcmp(inputBuffer, "hello") == 0)
    {
        hello();        
    }
    else if(strcmp(inputBuffer, "about") == 0)
    {
        about();
    }
    else if(strcmp(inputBuffer, "help") == 0)
    {
        help();
    }
    else if(strcmp(inputBuffer, "Help") == 0)
    {
        Help();
    }
    else if(strcmp(inputBuffer, "license") == 0)
    {
        license();
    }
    else if(strcmp(inputBuffer, "song") == 0)
    {
        super_idol();
    }
    else if(inputBuffer[0] == 'a' && inputBuffer[1] == 'd' && inputBuffer[2] == 'd')
    {
        char op1[10], op2[10];
        int opc1 = 0, opc2 = 0;

        int i = 4;

        for(; inputBuffer[i] != ','; i++)
        {
            op1[opc1] = inputBuffer[i];
            opc1++;
        }

        i++;

        for(; inputBuffer[i] != ']'; i++)
        {
            op2[opc2] = inputBuffer[i];
            opc2++;
        }

        op2[opc2] = '\0';
        op1[opc1] = '\0';

        GlobalRenderer->Print(to_string((int64_t)(atoi(op1) + atoi(op2))));
        currentInput = 0;
        GlobalRenderer->Next();
    }
    else if(inputBuffer[0] == 's' && inputBuffer[1] == 'u' && inputBuffer[2] == 'b')
    {
        char op1[10], op2[10];
        int opc1 = 0, opc2 = 0;

        int i = 4;

        for(; inputBuffer[i] != ','; i++)
        {
            op1[opc1] = inputBuffer[i];
            opc1++;
        }

        i++;

        for(; inputBuffer[i] != ']'; i++)
        {
            op2[opc2] = inputBuffer[i];
            opc2++;
        }

        op2[opc2] = '\0';
        op1[opc1] = '\0';

        GlobalRenderer->Print(to_string((int64_t)(atoi(op1) - atoi(op2))));
        currentInput = 0;
        GlobalRenderer->Next();
    }
    else if(inputBuffer[0] == 'm' && inputBuffer[1] == 'u' && inputBuffer[2] == 'l')
    {
        char op1[10], op2[10];
        int opc1 = 0, opc2 = 0;

        int i = 4;

        for(; inputBuffer[i] != ','; i++)
        {
            op1[opc1] = inputBuffer[i];
            opc1++;
        }

        i++;

        for(; inputBuffer[i] != ']'; i++)
        {
            op2[opc2] = inputBuffer[i];
            opc2++;
        }

        op2[opc2] = '\0';
        op1[opc1] = '\0';

        GlobalRenderer->Print(to_string((int64_t)(atoi(op1) * atoi(op2))));
        currentInput = 0;
        GlobalRenderer->Next();
    }
    else if(inputBuffer[0] == 'd' && inputBuffer[1] == 'i' && inputBuffer[2] == 'v')
    {
        char op1[10], op2[10];
        int opc1 = 0, opc2 = 0;

        int i = 4;

        for(; inputBuffer[i] != ','; i++)
        {
            op1[opc1] = inputBuffer[i];
            opc1++;
        }

        i++;

        for(; inputBuffer[i] != ']'; i++)
        {
            op2[opc2] = inputBuffer[i];
            opc2++;
        }

        op2[opc2] = '\0';
        op1[opc1] = '\0';

        GlobalRenderer->Print(to_string((int64_t)(atoi(op1) / atoi(op2))));
        currentInput = 0;
        GlobalRenderer->Next();
    }
    else
    {
        GlobalRenderer->Print("Comando nao reconhecido");
        prinln(inputBuffer);
        GlobalRenderer->Next();
    }
    currentInput = 0; // Reseta o input
}

void inputclear()
{
    for(int i = 0 ; i < 1024; i++)
    {
        inputBuffer[i] = 0;
    }
}

void HandleKeyboard(uint8_t scancode){

    switch (scancode){
        case LeftShift:
            isLeftShiftPressed = true;
            return;
        case LeftShift + 0x80:
            isLeftShiftPressed = false;
            return;
        case RightShift:
            isRightShiftPressed = true;
            return;
        case RightShift + 0x80:
            isRightShiftPressed = false;
            return;
        case Enter:
            GlobalRenderer->Next();
            if(currentInput > 0)
            {
                execute();
                inputclear();
                currentInput = 0;
                GlobalRenderer->Print("ZuimOS>: ");
            }
            return;
        case Spacebar:
            GlobalRenderer->PutChar(' ');
            return;
        case BackSpace:
           GlobalRenderer->ClearChar();
           return;
    }

    char ascii = QWERTYKeyboard::Translate(scancode, isLeftShiftPressed | isRightShiftPressed);

    if (ascii != 0){
        GlobalRenderer->PutChar(ascii);
        if(currentInput >=0 && currentInput < 1024)
        {
            inputBuffer[currentInput] = ascii;
            currentInput++;
        }
    }

}