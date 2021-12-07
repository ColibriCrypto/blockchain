// Copyright (c) 2012- 2021     
// Copyright (c)    2021 The     developers
// Copyright (c)   2021     
//      
//   

#ifndef CLBI_VERSION_H
#define CLBI_VERSION_H

/**
 * network protocol versioning
 */

static const int PROTOCOL_VERSION = 70924;

//! initial proto version, to be increased after version/verack negotiation
static const int INIT_PROTO_VERSION = 209;

//! disconnect from peers older than this proto version
static const int MIN_PEER_PROTO_VERSION_BEFORE_ENFORCEMENT = 70922;
static const int MIN_PEER_PROTO_VERSION_AFTER_ENFORCEMENT = 70923;

//! Version where BIP155 was introduced
static const int MIN_BIP155_PROTOCOL_VERSION = 70923;

// Make sure that none of the values above collide with
// `ADDRV2_FORMAT`.

#endif // CLBI_VERSION_H
