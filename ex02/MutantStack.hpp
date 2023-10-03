/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:12:37 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/20 05:40:04 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                            MUTANT STACK CLASS                              */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>
#include <vector>
#include <list>
#include <deque>

template<typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    private:
        // private member attributes
        // private member functions
    public:
        // constructors
        MutantStack<T, Container>( void ) { return ; }
        MutantStack<T, Container>( MutantStack<T, Container> const &src ) { *this = src; }
        // destructor
        ~MutantStack<T, Container>( void ) { return ; }
        // operators overload;
        MutantStack<T, Container>&  operator=( MutantStack<T, Container> const &src ) {
            std::stack<T, Container>::operator=(src);
            return (*this);
        }
        // getter, setter
        // public member functions
        typedef typename std::stack<T, Container>::container_type::iterator iterator;
        iterator    begin( void ) { return (this->c.begin()); }
        iterator    end( void ) { return (this->c.end()); }
        // exception classes
};

#endif