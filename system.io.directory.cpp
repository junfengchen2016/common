#include "system.io.directory.h"

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;

namespace chenjunfeng
{
	namespace System
	{
		namespace IO
		{
			vector<string> Directory::GetFiles(string path, string searchPattern, SearchOption searchOption)
			{
				vector<string> ret;

				fs::path _path(path);

				if(!fs::exists(path)) return ret;

				if (searchOption == SearchOption::SearchOption_AllDirectories)
				{
					fs::recursive_directory_iterator end_iter;
					for (boost::filesystem::recursive_directory_iterator iter(_path); iter != end_iter; iter++)
					{
						if (boost::filesystem::is_directory(iter->path())) continue;

						string extension = iter->path().extension().string();
						boost::to_lower(extension);
						if (extension != searchPattern) continue;

						string pathname = iter->path().string();
						ret.push_back(pathname);
					}
				}
				else
				{
					fs::directory_iterator end_iter;
					for (boost::filesystem::directory_iterator iter(_path); iter != end_iter; iter++)
					{
						string extension = iter->path().extension().string();
						boost::to_lower(extension);
						if (extension != searchPattern) continue;

						string pathname = iter->path().string();
						ret.push_back(pathname);
					}
				}

				return ret;
			}

			void Directory::_CreateDirectory(string path)
			{
				boost::filesystem::create_directories(boost::filesystem::path(path));
			}

			void Directory::Delete(string path, bool recursive)
			{
				try{
					fs::path b_dir_path(path);
					if (fs::exists(b_dir_path))
					{
						if (recursive)
							fs::remove_all(b_dir_path);
						else
							fs::remove(b_dir_path);
					}
				}
				catch (fs::filesystem_error & e)
				{
					//LOG4CXX_WARN(g_logger,
					//	"DeleteDirectory "
					//	<< "path1=" << e.path1().directory_string() << " , "
					//	<< "path2=" << e.path2().directory_string() << " , "
					//	<< "what=" << e.what() << " , "
					//	<< "code=" << e.code().value() << ","
					//	<< "codemessage=" << e.code().message() << ""
					//	)
					//	return false;
				}
				//return true;
			}
		}
	}
}