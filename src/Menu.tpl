#include <utility> //forward
template<typename ... Args>
void Menu::setPosition(Args&& ... args)
{
	//_button.setPosition(std::forward<Args>(args)...);
	_btSingle.setPosition(std::forward<Args>(args)...);
	_btMulti.setPosition(std::forward<Args>(args)...);
	_btQuit.setPosition(std::forward<Args>(args)...);
}


