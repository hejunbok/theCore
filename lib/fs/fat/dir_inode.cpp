#include "fat/dir_inode.hpp"
#include "src/pff.h"

using namespace fat;

dir_inode::dir_inode(FATFS *fs, path_ptr path)
    :m_fs{fs}
    ,m_path{path}
{

}

dir_inode::~dir_inode()
{

}

dir_inode::type dir_inode::get_type() const
{
    return dir_inode::type::dir;
}

fs::dir_ptr dir_inode::open_dir()
{
    return nullptr;
}

ssize_t dir_inode::size() const
{
    return -1;
}

ssize_t dir_inode::get_name(const char *buf, size_t buf_sz) const
{
    (void) buf;
    (void) buf_sz;
    return -1;
}
