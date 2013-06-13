#include "shared_config.hh"
#include KVDB_ROW_TYPE_INCLUDE

void kvproto::fill() {
    rt_ = row_type::type_id;
    maxkeylen_ = MaxKeyLen;
    maxrowlen_ = MaxRowLen;
}

bool kvproto::check() {
    return rt_ == row_type::type_id &&
           maxkeylen_ == MaxKeyLen &&
           maxrowlen_ == MaxRowLen;
}

