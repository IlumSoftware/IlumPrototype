#include <utility> //forward
template<typename ... Args>
void Menu::setPosition(Args&& ... args)
{
	_button.setPosition(std::forward<Args>(args)...);
}


