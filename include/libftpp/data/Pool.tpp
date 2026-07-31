/*=======Pool:Object========*/

// constructor

template<typename TType>
template<typename UType>
Pool<TType>::Object<UType>::Object()
{
}

template<typename TType>
template<typename UType>
Pool<TType>::Object<UType>::Object(UType content) : _content(content) 
{
}

template<typename TType>
template<typename UType>
Pool<TType>::Object<UType>::~Object()
{
    std::cout << "Object destroyed" << std::endl;
}

// Methodes

template<typename TType>
template<typename UType>
UType Pool<TType>::Object<UType>::getContent() const
{
    return _content;
}

/*=======Pool========*/

template<typename TType>
Pool<TType>::Pool()
{
}

template<typename TType>
Pool<TType>::Pool(TType a) : _prototype(a)
{
}

template<typename TType>
Pool<TType>::~Pool()
{
}

// template<typename TType>
// Pool<TType>::Pool()
// {
// }