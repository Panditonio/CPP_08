/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:37:56 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/20 04:43:29 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SPAN CLASS                                   */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <cmath>

class Span
{
    private:
        // private member attributes
        unsigned int        _sSize;
        std::vector<int>    _stored;
        // private member functions
        // default constructor
        Span( void );
    public:
        // other constructors
        Span( unsigned int const n );
        Span( Span const &src );
        // destructor
        ~Span( void );
        // operators overload;
        Span&   operator=( Span const &src );
        // getter, setter
        unsigned int    getSize( void ) const;
        unsigned int    getMaxSize( void ) const;
        unsigned int    getMaxValue( void ) const;
        unsigned int    getMinValue( void ) const;
        // public member functions
        void            addNumber( int nbr );
        void            addX( std::vector<int>::iterator begin,
                                std::vector<int>::iterator end );
        unsigned int    shortestSpan( void ) const;
        unsigned int    longestSpan( void ) const;
        // exception classes
        class MaxedOutException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[ERROR] Span maxed out";
                }
        };
        class NoDistanceException : public std::exception {
            public:
                virtual const char* what() const throw() { 
                    return "[ERROR] Span distance null";
                }
        };
};

std::ostream&   operator<<( std::ostream &os, Span const &rhs );

#endif