// github.com/NoSkill33
#ifndef TERMCOLOR_HPP_
#define TERMCOLOR_HPP_

#if defined(_WIN32) || defined(_WIN64)
#   define TERMCOLOR_OS_WINDOWS
#elif defined(__APPLE__)
#   define TERMCOLOR_OS_MACOS
#elif defined(__unix__) || defined(__unix)
#   define TERMCOLOR_OS_LINUX
#else
#   error unsupported platform
#endif

#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
#   include <unistd.h>
#elif defined(TERMCOLOR_OS_WINDOWS)
#   include <io.h>
#   include <windows.h>
#endif


#include <iostream>
#include <cstdio>



namespace termcolor
{

	namespace _internal
	{
		static int colorize_index = std::ios_base::xalloc();

		inline FILE* get_standard_stream(const std::ostream& stream);
		inline bool is_colorized(std::ostream& stream);
		inline bool is_atty(const std::ostream& stream);

#if defined(TERMCOLOR_OS_WINDOWS)
		inline void win_change_attributes(std::ostream& stream, int foreground, int background = -1);
#endif
	}

	inline
		std::ostream& colorize(std::ostream& stream)
	{
		stream.iword(_internal::colorize_index) = 1L;
		return stream;
	}

	inline
		std::ostream& nocolorize(std::ostream& stream)
	{
		stream.iword(_internal::colorize_index) = 0L;
		return stream;
	}

	inline
		std::ostream& reset(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[00m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1, -1);
#endif
		}
		return stream;
	}


	inline
		std::ostream& bold(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[1m";
#elif defined(TERMCOLOR_OS_WINDOWS)
#endif
		}
		return stream;
	}


	inline
		std::ostream& dark(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[2m";
#elif defined(TERMCOLOR_OS_WINDOWS)
#endif
		}
		return stream;
	}


	inline
		std::ostream& underline(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[4m";
#elif defined(TERMCOLOR_OS_WINDOWS)
#endif
		}
		return stream;
	}


	inline
		std::ostream& blink(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[5m";
#elif defined(TERMCOLOR_OS_WINDOWS)
#endif
		}
		return stream;
	}


	inline
		std::ostream& reverse(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[7m";
#elif defined(TERMCOLOR_OS_WINDOWS)
#endif
		}
		return stream;
	}


	inline
		std::ostream& concealed(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[8m";
#elif defined(TERMCOLOR_OS_WINDOWS)
#endif
		}
		return stream;
	}


	inline
		std::ostream& grey(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[30m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				0   // grey (black)
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& red(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[31m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_RED
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& green(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[32m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_GREEN
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& yellow(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[33m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_GREEN | FOREGROUND_RED
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& blue(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[34m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_BLUE
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& magenta(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[35m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_BLUE | FOREGROUND_RED
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& cyan(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[36m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_BLUE | FOREGROUND_GREEN
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& white(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[37m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream,
				FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED
			);
#endif
		}
		return stream;
	}



	inline
		std::ostream& on_grey(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[40m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				0   // grey (black)
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_red(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[41m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_RED
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_green(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[42m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_GREEN
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_yellow(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[43m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_GREEN | BACKGROUND_RED
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_blue(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[44m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_BLUE
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_magenta(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[45m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_BLUE | BACKGROUND_RED
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_cyan(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[46m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_GREEN | BACKGROUND_BLUE
			);
#endif
		}
		return stream;
	}

	inline
		std::ostream& on_white(std::ostream& stream)
	{
		if (_internal::is_colorized(stream))
		{
#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			stream << "\033[47m";
#elif defined(TERMCOLOR_OS_WINDOWS)
			_internal::win_change_attributes(stream, -1,
				BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_RED
			);
#endif
		}

		return stream;
	}




	namespace _internal
	{

		inline
			FILE* get_standard_stream(const std::ostream& stream)
		{
			if (&stream == &std::cout)
				return stdout;
			else if ((&stream == &std::cerr) || (&stream == &std::clog))
				return stderr;

			return 0;
		}


		inline
			bool is_colorized(std::ostream& stream)
		{
			return is_atty(stream) || static_cast<bool>(stream.iword(colorize_index));
		}


		inline
			bool is_atty(const std::ostream& stream)
		{
			FILE* std_stream = get_standard_stream(stream);


			if (!std_stream)
				return false;

#if defined(TERMCOLOR_OS_MACOS) || defined(TERMCOLOR_OS_LINUX)
			return ::isatty(fileno(std_stream));
#elif defined(TERMCOLOR_OS_WINDOWS)
			return ::_isatty(_fileno(std_stream));
#endif
		}

#if defined(TERMCOLOR_OS_WINDOWS)

		inline void win_change_attributes(std::ostream& stream, int foreground, int background)
		{

			static WORD defaultAttributes = 0;


			if (!_internal::is_atty(stream))
				return;

			HANDLE hTerminal = INVALID_HANDLE_VALUE;
			if (&stream == &std::cout)
				hTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
			else if (&stream == &std::cerr)
				hTerminal = GetStdHandle(STD_ERROR_HANDLE);

			if (!defaultAttributes)
			{
				CONSOLE_SCREEN_BUFFER_INFO info;
				if (!GetConsoleScreenBufferInfo(hTerminal, &info))
					return;
				defaultAttributes = info.wAttributes;
			}


			if (foreground == -1 && background == -1)
			{
				SetConsoleTextAttribute(hTerminal, defaultAttributes);
				return;
			}


			CONSOLE_SCREEN_BUFFER_INFO info;
			if (!GetConsoleScreenBufferInfo(hTerminal, &info))
				return;

			if (foreground != -1)
			{
				info.wAttributes &= ~(info.wAttributes & 0x0F);
				info.wAttributes |= static_cast<WORD>(foreground);
			}

			if (background != -1)
			{
				info.wAttributes &= ~(info.wAttributes & 0xF0);
				info.wAttributes |= static_cast<WORD>(background);
			}

			SetConsoleTextAttribute(hTerminal, info.wAttributes);
		}
#endif 

	}

}


#undef TERMCOLOR_OS_WINDOWS
#undef TERMCOLOR_OS_MACOS
#undef TERMCOLOR_OS_LINUX

#endif 