/*=======Pool:Object========*/

// constructor

template<typename TType>
Pool<TType>::Object::Object()
{
}

template<typename TType>
Pool<TType>::Object::Object(TType content) : _content(content) 
{
}

template<typename TType>
Pool<TType>::Object::Object(const Object& original) : _content(original.getContent())
{
}

template<typename TType>
Pool<TType>::Object::~Object()
{
    // std::cout << "Object destroyed" << std::endl;
}

// methodes

template<typename TType>
TType Pool<TType>::Object::getContent() const
{
    return _content;
}

/*=======Pool========*/

// constructor

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

// methodes

// template<typename TType>
// Pool<TType>::Pool()
// {
// }