/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include "bcache.h"

#include <linux/slab.h>
#include <linux/bitops.h>
#include <linux/freezer.h>
#include <linux/hash.h>
#include <linux/kthread.h>

/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#define MAX_NEED_GC		64
#define MAX_SAVE_PRIO		72

#define PTR_DIRTY_BIT		(((uint64_t) 1 << 36))

#define PTR_HASH(c, k)
	(((k)->ptr[0] >> c->bucket_bits) | PTR_GEN(k, 0))

#define insert_lock(s, b)	((b)->level <= (s)->lock)

/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#define btree(fn, key, b, op, ...)
({
	int _r, l = (b)->level - 1;					\
	bool _w = l <= (op)->lock;					\
	struct btree *_child = bch_btree_node_get((b)->c, op, key, l,	\
						  _w, b);		\
	if (!IS_ERR(_child)) {						\
		_r = bch_btree_ ## fn(_child, op, ##__VA_ARGS__);	\
		rw_unlock(_w, _child);					\
	} else
		_r = PTR_ERR(_child);
	_r;
})

/**
 * btree_root - call a function on the root of the btree
 *
 */
#define btree_root(fn, c, op, ...)
({
})

static inline struct bset *write_block(struct btree *b)
{}

static void bch_btree_init_next(struct btree *b)
{}

/* Btree key manipulation */

void bkey_put(struct cache_set *c, struct bkey *k)
{}

/* Btree IO */

static uint64_t btree_csum_set(struct btree *b, struct bset *i)
{}

void bch_btree_node_read_done(struct btree *b)
{}

static void btree_node_read_endio(struct bio *bio)
{}

static void btree_node_read(struct btree *b)
{}

static void btree_complete_write(struct btree *b, struct btree_write *w)
{}

static void btree_node_write_unlock(struct closure *cl)
{}

static void __btree_node_write_done(struct closure *cl)
{}

static void btree_node_write_done(struct closure *cl)
{}

static void btree_node_write_endio(struct bio *bio)
{}

static void do_btree_node_write(struct btree *b)
{}

void __bch_btree_node_write(struct btree *b, struct closure *parent)
{}

void bch_btree_node_write(struct btree *b, struct closure *parent)
{}

static void bch_btree_node_write_sync(struct btree *b)
{}

static void btree_node_write_work(struct work_struct *w)
{}

static void bch_btree_leaf_dirty(struct btree *b, atomic_t *journal_ref)
{}

/*
 * Btree in memory cache - allocation/freeing
 * mca -> memory cache
 */

#define mca_reserve(c)	(((c->root && c->root->level)		\
 			  ? c->root->level : 1) * 8 + 16)