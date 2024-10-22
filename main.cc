// NOTES:
// - this is a coding kata, it serves no purpose
// - it is C++98 code and not compilable with newer language standards because it uses std::unary_function which, as of today, is deleted

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>

namespace example
{
    template<typename ArgumentType, typename ResultType>
    struct invoke_delegate_0 : public std::unary_function<ArgumentType, ResultType>
    {
        typedef typename std::unary_function<ArgumentType, ResultType>::argument_type argument_type;
        typedef typename std::unary_function<ArgumentType, ResultType>::result_type result_type;

        invoke_delegate_0 ();
        invoke_delegate_0 (const invoke_delegate_0& other);
        virtual ~invoke_delegate_0 ();

        invoke_delegate_0& operator= (const invoke_delegate_0& other);

        result_type operator() (argument_type argument) const;
    };

    template<typename ArgumentType, typename ResultType, typename Parameter1Type>
    struct invoke_delegate_1 : public std::unary_function<ArgumentType, ResultType>
    {
    public:
        typedef typename std::unary_function<ArgumentType, ResultType>::argument_type argument_type;
        typedef typename std::unary_function<ArgumentType, ResultType>::result_type result_type;
        typedef Parameter1Type parameter_1_type;

    private:
        parameter_1_type parameter_1;
        
    public:
        invoke_delegate_1 (parameter_1_type parameter_1);
        invoke_delegate_1 (const invoke_delegate_1& other);
        virtual ~invoke_delegate_1 ();

        invoke_delegate_1& operator= (const invoke_delegate_1& other);

        result_type operator() (argument_type argument) const;
    };

    template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
    struct invoke_delegate_2 : public std::unary_function<ArgumentType, ResultType>
    {
    public:
        typedef typename std::unary_function<ArgumentType, ResultType>::argument_type argument_type;
        typedef typename std::unary_function<ArgumentType, ResultType>::result_type result_type;
        typedef Parameter1Type parameter_1_type;
        typedef Parameter2Type parameter_2_type;
    
    private:
        parameter_1_type parameter_1;
        parameter_2_type parameter_2;

    public:
        invoke_delegate_2 (parameter_1_type parameter_1, parameter_2_type parameter_2);
        invoke_delegate_2 (const invoke_delegate_2& other);
        virtual ~invoke_delegate_2 ();

        invoke_delegate_2& operator= (const invoke_delegate_2& other);

        result_type operator() (argument_type argument) const;
    };

    template<typename Function>
    class delegate_base
    {
    public:
        typedef Function function_type;
        typedef std::map<unsigned, function_type> container_type;

    private:
        unsigned id;

    protected:
        container_type delegate_store;

    public:
        explicit delegate_base ();
        explicit delegate_base (const delegate_base&); /* not implemented */
        virtual ~delegate_base ();

        delegate_base& operator= (const delegate_base&); /* not implemented */

        unsigned add (const function_type function);
        void remove (const unsigned id);
    };

    template<typename Function>
    class delegate;

    template<>
    class delegate<void (*) ()> : public delegate_base<void (*) ()>
    {
    public:
        typedef void (*function_type) ();
        typedef void return_type;

        explicit delegate ();
        explicit delegate (const delegate&); /* not implemented */
        virtual ~delegate ();

        delegate& operator= (const delegate&); /* not implemented */

        return_type invoke () const;
    };

    template<typename Argument1Type>
    class delegate<void (*) (Argument1Type)> : public delegate_base<void (*) (Argument1Type)>
    {
    public:
        typedef void (*function_type) (Argument1Type);
        typedef void return_type;
        typedef Argument1Type argument_1_type;

        explicit delegate ();
        explicit delegate (const delegate& other); /* not implemented */
        virtual ~delegate ();

        delegate& operator= (const delegate& other); /* not implemented */

        return_type invoke (argument_1_type argument_1) const;
    };

    template<typename Argument1Type, typename Argument2Type>
    class delegate<void (*) (Argument1Type, Argument2Type)> : public delegate_base<void (*) (Argument1Type, Argument2Type)>
    {
    public:
        typedef void (*function_type) (Argument1Type, Argument2Type);
        typedef void return_type;
        typedef Argument1Type argument_1_type;
        typedef Argument2Type argument_2_type;

        explicit delegate ();
        explicit delegate (const delegate&); /* not implemented */
        virtual ~delegate ();

        delegate& operator= (const delegate&); /* not implemented */

        return_type invoke (argument_1_type argument_1, argument_2_type argument_2) const;
    };

	class username_changed_event_args
	{
    private:
		std::string old_name;
		std::string new_name;
	
    public:
		username_changed_event_args (const std::string& old_name, const std::string& new_name);
        explicit username_changed_event_args (const username_changed_event_args& other);
        ~username_changed_event_args ();

        username_changed_event_args& operator= (const username_changed_event_args& other);
		
		const std::string& get_old_name () const;
		const std::string& get_new_name () const;
	};

	class user
	{
    public:
        typedef void (*username_changed_handler_type) (const user&, const username_changed_event_args&);

    private:
		std::string name;
        delegate<username_changed_handler_type> on_username_changed;
	
    public:
		explicit user (const std::string& name);
        explicit user (const user&); /* not implemented */
        ~user ();

        user& operator= (const user&); /* not implemented */
		
        const std::string& get_name () const;
        void set_name (const std::string& new_name);

        unsigned add_username_changed_handler (const username_changed_handler_type username_changed_handler);
        void remove_username_changed_handler (const unsigned id);
	};
}

/**
 * template<typename ArgumentType, typename ResultType>
 * class example::invoke_delegate_0<ArgumentType, ResultType>
**/

template<typename ArgumentType, typename ResultType>
example::invoke_delegate_0<ArgumentType, ResultType>::invoke_delegate_0 ()
    : std::unary_function<ArgumentType, ResultType> ()
{}

template<typename ArgumentType, typename ResultType>
example::invoke_delegate_0<ArgumentType, ResultType>::invoke_delegate_0 (const invoke_delegate_0& other)
    : std::unary_function<ArgumentType, ResultType> (other)
{}

template<typename ArgumentType, typename ResultType>
example::invoke_delegate_0<ArgumentType, ResultType>::~invoke_delegate_0 ()
{}

template<typename ArgumentType, typename ResultType>
example::invoke_delegate_0<ArgumentType, ResultType>& example::invoke_delegate_0<ArgumentType, ResultType>::operator= (const invoke_delegate_0& other)
{
    std::unary_function<ArgumentType, ResultType>::operator= (other);
    return *this;
}

template<typename ArgumentType, typename ResultType>
typename example::invoke_delegate_0<ArgumentType, ResultType>::result_type example::invoke_delegate_0<ArgumentType, ResultType>::operator() (argument_type argument) const
{
    return (*argument.second) ();
}

/**
 * template<typename ArgumentType, typename ResultType, typename Parameter1Type>
 * class example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>
**/

template<typename ArgumentType, typename ResultType, typename Parameter1Type>
example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>::invoke_delegate_1 (parameter_1_type parameter_1)
    : std::unary_function<ArgumentType, ResultType> (),
    parameter_1 (parameter_1)
{}

template<typename ArgumentType, typename ResultType, typename Parameter1Type>
example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>::invoke_delegate_1 (const invoke_delegate_1& other)
    : std::unary_function<ArgumentType, ResultType> (),
    parameter_1 (other.parameter_1)
{}

template<typename ArgumentType, typename ResultType, typename Parameter1Type>
example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>::~invoke_delegate_1 ()
{}

template<typename ArgumentType, typename ResultType, typename Parameter1Type>
example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>& example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>::operator= (const invoke_delegate_1& other)
{
    if (&other != this)
        this->parameter_1 = other.parameter_1;
    return *this;
}

template<typename ArgumentType, typename ResultType, typename Parameter1Type>
typename example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>::result_type example::invoke_delegate_1<ArgumentType, ResultType, Parameter1Type>::operator() (argument_type argument) const
{
    return (*argument.second) (this->parameter_1);
}

/**
 * template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
 * class example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>
**/

template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>::invoke_delegate_2 (parameter_1_type parameter_1, parameter_2_type parameter_2)
    : std::unary_function<ArgumentType, ResultType> (),
    parameter_1 (parameter_1),
    parameter_2 (parameter_2)
{}

template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>::invoke_delegate_2 (const invoke_delegate_2& other)
    : std::unary_function<ArgumentType, ResultType> (other),
    parameter_1 (other.parameter_1),
    parameter_2 (other.parameter_2)
{}

template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>::~invoke_delegate_2 ()
{}

template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>& example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>::operator= (const invoke_delegate_2& other)
{
    if (&other != this)
    {
        this->parameter_1 = other.parameter_1;
        this->parameter_2 = other.parameter_2;
    }

    return *this;
}

template<typename ArgumentType, typename ResultType, typename Parameter1Type, typename Parameter2Type>
typename example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>::result_type example::invoke_delegate_2<ArgumentType, ResultType, Parameter1Type, Parameter2Type>::operator() (argument_type argument) const
{
    return (*argument.second) (this->parameter_1, this->parameter_2);
}

/**
 * template<typename Function>
 * class example::delegate_base<Function>
**/

template<typename Function>
example::delegate_base<Function>::delegate_base ()
    : id (0U),
    delegate_store ()
{}

template<typename Function>
example::delegate_base<Function>::~delegate_base ()
{}

template<typename Function>
unsigned example::delegate_base<Function>::add (const function_type function)
{
    if (!function)
        throw std::invalid_argument ("function cannot be NULL");

    if (std::numeric_limits<unsigned>::max () == this->id)
        throw std::overflow_error ("Delegate cannot store more delegates");

    const unsigned new_id (this->id++);
    this->delegate_store[new_id] = function;
    return new_id;
}

template<typename Function>
void example::delegate_base<Function>::remove (const unsigned id_to_remove)
{
    this->delegate_store.erase (id_to_remove);
}

/**
 * template<>
 * class example::delegate<void (*) ()>
**/

example::delegate<void (*) ()>::delegate ()
    : delegate_base<void (*) ()> ()
{}

example::delegate<void (*) ()>::~delegate ()
{}

example::delegate<void (*) ()>::return_type example::delegate<void (*) ()>::invoke () const
{
    typedef container_type::const_iterator const_iterator;
    typedef const_iterator::value_type value_type;

    const invoke_delegate_0<value_type, void> delegate_0;

    std::for_each   (
                        static_cast <const_iterator> (this->delegate_store.begin ()),
                        static_cast <const_iterator> (this->delegate_store.end ()),
                        delegate_0
                    );
}

/**
 * template<typename Argument1Type>
 * class example::delegate<void (*) (Argument1Type)>
**/

template<typename Argument1Type>
example::delegate<void (*) (Argument1Type)>::delegate ()
    : delegate_base<void (*) (argument_1_type)> ()
{}

template<typename Argument1Type>
example::delegate<void (*) (Argument1Type)>::~delegate ()
{}

template<typename Argument1Type>
typename example::delegate<void (*) (Argument1Type)>::return_type example::delegate<void (*) (Argument1Type)>::invoke (argument_1_type argument_1) const
{
    typedef typename delegate_base<function_type>::container_type container_type;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename const_iterator::value_type value_type;

    const invoke_delegate_1<value_type, void, argument_1_type> delegate_1 (argument_1);
    
    std::for_each   (
                        static_cast <const_iterator> (this->delegate_store.begin ()),
                        static_cast <const_iterator> (this->delegate_store.end ()),
                        delegate_1
                    );
}

/**
 * template<typename Argument1Type, typename Argument2Type>
 * class example::delegate<void (*) (Argument1Type, Argument2Type)>
**/

template<typename Argument1Type, typename Argument2Type>
example::delegate<void (*) (Argument1Type, Argument2Type)>::delegate ()
    : delegate_base<void (*) (Argument1Type, Argument2Type)> ()
{}

template<typename Argument1Type, typename Argument2Type>
example::delegate<void (*) (Argument1Type, Argument2Type)>::~delegate ()
{}

template<typename Argument1Type, typename Argument2Type>
typename example::delegate<void (*) (Argument1Type, Argument2Type)>::return_type example::delegate<void (*) (Argument1Type, Argument2Type)>::invoke (argument_1_type argument_1, argument_2_type argument_2) const
{
    typedef typename delegate_base<function_type>::container_type container_type;
    typedef typename container_type::const_iterator const_iterator;
    typedef typename const_iterator::value_type value_type;
    
    const invoke_delegate_2<value_type, void, argument_1_type, argument_2_type> delegate2 (argument_1, argument_2);

    std::for_each   (
                        static_cast <const_iterator> (this->delegate_store.begin ()),
                        static_cast <const_iterator> (this->delegate_store.end ()),
                        delegate2
                    );
}

/**
 * class example::username_changed_event_args
**/

example::username_changed_event_args::username_changed_event_args (const std::string& old_name, const std::string& new_name)
    : old_name (old_name),
    new_name (new_name)
{}

example::username_changed_event_args::username_changed_event_args (const username_changed_event_args& other)
    : old_name (other.old_name),
    new_name (other.new_name)
{}

example::username_changed_event_args::~username_changed_event_args ()
{}

example::username_changed_event_args& example::username_changed_event_args::operator= (const username_changed_event_args& other)
{
    if (&other != this)
    {
        old_name = other.old_name;
        new_name = other.new_name;
    }

    return *this;
}
		
const std::string& example::username_changed_event_args::get_old_name () const
{
    return old_name;
}
		
const std::string& example::username_changed_event_args::get_new_name () const
{
    return new_name;
}

/**
 * class example::user
**/

example::user::user (const std::string& name)
    : name (name),
    on_username_changed ()
{}

example::user::~user ()
{}

const std::string& example::user::get_name () const
{
    return name;
}

void example::user::set_name (const std::string& new_name)
{
    const username_changed_event_args event_args (name, new_name);
    name = new_name;
    on_username_changed.invoke (static_cast <const user&> (*this), static_cast <const username_changed_event_args&> (event_args));
}

unsigned example::user::add_username_changed_handler (const username_changed_handler_type username_changed_handler)
{
    return on_username_changed.add (username_changed_handler);
}

void example::user::remove_username_changed_handler (const unsigned id)
{
    on_username_changed.remove (id);
}

void name_changed (const example::user& user, const example::username_changed_event_args& event_args);

using namespace std;

int main ()
{
    example::user john ("John");
    john.add_username_changed_handler (&name_changed);
    john.set_name ("Johnny");

    return 0;
}

void name_changed (const example::user& /* user */, const example::username_changed_event_args& event_args)
{
    cout << "Name changed from " << event_args.get_old_name () << " to " << event_args.get_new_name () << endl;
}
