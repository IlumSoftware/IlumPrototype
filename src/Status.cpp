#include "Status.h"

Status::Status(): _currentStatus(Status::MainMenu){};



int Status::getCurrentStatus()
{
    return _currentStatus;
}

void Status::setCurrentStatus(int _status)
{
    _currentStatus=_status;
}

int Status::getCurrentButton()
{
    return _currentButton;
}

void Status::setCurrentButton(int _button)
{
    _currentButton=_button;
}
