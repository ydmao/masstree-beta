/* Masstree
 * Eddie Kohler, Yandong Mao, Robert Morris
 * Copyright (c) 2012-2013 President and Fellows of Harvard College
 * Copyright (c) 2012-2013 Massachusetts Institute of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, subject to the conditions
 * listed in the Masstree LICENSE file. These conditions include: you must
 * preserve this copyright notice, and you cannot mention the copyright
 * holders in advertising related to the Software without their permission.
 * The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
 * notice is a summary of the Masstree LICENSE file; the license in that file
 * is legally binding.
 */
#ifndef KVPROTO_HH
#define KVPROTO_HH 1
#include "shared_config.hh"

struct kvproto {
    kvproto() {
        fill();
    }
    void fill();
    bool check();
  private:
    rowtype_id rt_;
    int maxkeylen_;
    int maxrowlen_;
};

enum {
    Cmd_None = 0,
    Cmd_Get,
    Cmd_Put,			// does not return status
    Cmd_Checkpoint,
    Cmd_Scan,
    Cmd_Remove,
    Cmd_Put_Status,
    Cmd_Max
};

enum result_t {
    NotFound = -2,
    Retry,
    OutOfDate,
    Inserted,
    Updated,
    Found,
    ScanDone
};

struct row_marker {
    enum { mt_remove = 1, mt_delta = 2 };
    int marker_type_;
};

template <typename R>
inline bool row_is_marker(const R* row) {
    return row->timestamp() & 1;
}

#endif
