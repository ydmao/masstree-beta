#include "shared_config.hh"
#include KVDB_ROW_TYPE_INCLUDE

void kvproto_init(struct kvproto &kvproto) {
    kvproto.p_rt = row_type::type_id;
    kvproto.p_maxkeylen = MaxKeyLen;
    kvproto.p_maxrowlen = MaxRowLen;
}

bool kvproto_check(const kvproto &kvproto) {
    if (kvproto.p_rt != row_type::type_id ||
        kvproto.p_maxkeylen != MaxKeyLen ||
        kvproto.p_maxrowlen != MaxRowLen)
        return false;
    return true;
}


