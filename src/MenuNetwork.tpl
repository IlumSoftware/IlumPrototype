#include <utility> //forward
template<typename ... Args>
void MenuNetwork::setPosition(Args&& ... args)
{
	_tfHostname.setPosition(std::forward<Args>(args)...);
}


