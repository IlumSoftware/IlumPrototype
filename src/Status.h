#ifndef STATUS_H
#define STATUS_H

class Status
{
    public:
        //Status(const Status&) = delete;
        Status& operator=(const Status&) = delete;
        Status();
        int getCurrentStatus();
        void setCurrentStatus(int _status);
        int getCurrentButton();
        void setCurrentButton(int _button);

        enum CurrentStatus: int {
            MainMenu,
            NetworkMenu,
            MultiGame,
            SingleGame,
            GameOver,
            Quit
        };

        enum CurrentButton: int {
            BClickSinglePlayer,
            BClickMultiPlayer,
            BClickQuit,
            Nothing
        };

    private:
        int _currentStatus;
        int _currentButton;

};

#endif
