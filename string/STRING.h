#pragma once

class STRING
{


public:
	//constructor
	//default
	STRING();
	//copy
	STRING(const STRING& str);
	//substring
	STRING(const STRING& str, size_t pos, size_t len = std::string::npos);
	//from c - string
	STRING(const char* s);
	//from buffer
	STRING(const char* s, size_t n);
	//fill constructor
	STRING(size_t n, char c);
	//range constructor
	template <class InputIterator>  STRING(InputIterator first, InputIterator last);
	//initializer list
	STRING(std::initializer_list<char> il);
	//move constructor
	STRING(STRING&& str) noexcept;

	//destructor
	~STRING();

	//operator=
	//string
	STRING& operator= (const STRING& str);
	//c - string
	STRING& operator= (const char* s);
	//character
	STRING& operator= (char c);
	//initializer list
	STRING& operator= (std::initializer_list<char> il);
	//move
	STRING& operator= (STRING&& str) noexcept;

	//iterator
	std::string::iterator begin() noexcept;
	std::string::const_iterator begin() const noexcept;

	std::string::iterator end() noexcept;
	std::string::const_iterator end() const noexcept;

	std::string::reverse_iterator rbegin() noexcept;
	std::string::const_reverse_iterator rbegin() const noexcept;

	std::string::reverse_iterator rend() noexcept;
	std::string::const_reverse_iterator rend() const noexcept;

	std::string::const_iterator cbegin() const noexcept;

	std::string::const_iterator cend() const noexcept;

	std::string::const_reverse_iterator crbegin() const noexcept;

	std::string::const_reverse_iterator crend() const noexcept;

	//capacity
	size_t size() const noexcept;

	size_t length() const noexcept;

	size_t max_size() const noexcept;

	void resize(size_t n);
	void resize(size_t n, char c);

	size_t capacity() const noexcept;

	void reserve(size_t n = 0);

	void clear() noexcept;

	bool empty() const noexcept;

	void shrink_to_fit();
};