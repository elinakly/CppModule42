#pragma once

class Array
{
	private:

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		const Array& operator=(const Array& other);
		~Array();
		class OutOfRangeException : public std::exception
		{	
			public:
				const char* what() const noexcept;
		};
		size_t size() const;
};