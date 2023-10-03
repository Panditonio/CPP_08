/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoineherbet <antoineherbet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 00:37:53 by antoineherb       #+#    #+#             */
/*   Updated: 2023/07/20 02:08:34 by antoineherb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ): _sSize(0) {
    return;
}

Span::Span( unsigned int const n ): _sSize(n), _stored(0) {
    return;
}

Span::Span( Span const &src ) {
    *this = src;
    return;
}

Span::~Span( void ) {
    _stored.clear();
    return;
}

Span&   Span::operator=( Span const &src ) {
    if (this != &src) {
        this->_sSize = src._sSize;
        this->_stored = src._stored;
    }
    return (*this);
}

void    Span::addNumber( int nbr ) {
    try {
        if (_stored.size() >= _sSize)
            throw MaxedOutException();
        else
            _stored.push_back(nbr);
    }
    catch (MaxedOutException &e) {
        std::cout << e.what() << std::endl;
    }
}

void    Span::addX( std::vector<int>::iterator begin, std::vector<int>::iterator end ) {
    try {
        _stored.insert(_stored.end(), begin, end);
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
    }
}

unsigned int    Span::shortestSpan( void ) const {
    try {
        if (_stored.empty() || _stored.size() == 1)
            throw NoDistanceException();
    }
    catch (NoDistanceException &e) {
        std::cout << e.what() << std::endl;
    }
    unsigned int    min_dist = Span::longestSpan();
    for (std::vector<int>::const_iterator it = _stored.begin(); it != _stored.end(); it++) {
        for (std::vector<int>::const_iterator fit = _stored.begin(); fit != _stored.end(); fit++) {
            if (it == fit)
                continue;
            if (std::abs(*fit - *it) < static_cast<int>(min_dist))
                min_dist = std::abs(*fit - *it);
        }
    }
    return (min_dist);
}

unsigned int    Span::longestSpan( void ) const {
    try {
        if (_stored.empty() || _stored.size() == 1)
            throw NoDistanceException();
    }
    catch (NoDistanceException &e) {
        std::cout << e.what() << std::endl;
    }
    return (*std::max_element(_stored.begin(), _stored.end())
            - *std::min_element(_stored.begin(), _stored.end()));
}

unsigned int    Span::getSize( void ) const {
    return (_stored.size());
}

unsigned int    Span::getMaxSize( void ) const {
    return (_sSize);
}

unsigned int    Span::getMaxValue( void ) const {
    return (*std::max_element(_stored.begin(), _stored.end()));
}

unsigned int    Span::getMinValue( void ) const {
    return (*std::min_element(_stored.begin(), _stored.end()));
}

std::ostream&   operator<<( std::ostream &os, Span const &rhs ) {
    os << "Vector<int> container maximum size is : " << rhs.getMaxSize()
        << ", and its actual size is : " << rhs.getSize()
        << "\nThe contained values range from : " << rhs.getMaxValue()
        << ", to : " << rhs.getMinValue()
        << "\nThe longest span is : " << rhs.longestSpan()
        << ", and the shortest span is : " << rhs.shortestSpan();
    return (os);
}