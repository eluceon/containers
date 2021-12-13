#ifndef NULLPTR_HPP
# define NULLPTR_HPP

namespace ft {
	class nullptr_t
	{
		public:
			nullptr_t() {}
			/*
			** Convert to any type of null non-member pointer
			*/
   			template<class T>
   				operator T*() const {
					return 0;
			}

			/*
			** Convert to any type of null member pointer
			*/
   			template<class C, class T>
      			operator T C::*() const {
					return 0;
			}   

		private:
			/*
			** Can't take address of nullptr
			*/
   			void operator&() const;
	};

	const nullptr_t	myNullptr;
}

#endif