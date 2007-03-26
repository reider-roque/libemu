/* @header@ */
#ifndef HAVE_EMU_MEMORY_H
#define HAVE_EMU_MEMORY_H

#include <inttypes.h>
#include <sys/types.h>

enum emu_segment {
	s_cs = 0, s_ss, s_ds, s_es, s_fs, s_gs
};

struct emu;
struct emu_memory;
struct emu_string;

struct emu_memory *emu_memory_new(struct emu *e);
void emu_memory_free(struct emu_memory *em);

/* read access, these functions return -1 on error  */
int32_t emu_memory_read_byte(struct emu_memory *m, uint32_t addr, uint8_t *byte);
int32_t emu_memory_read_word(struct emu_memory *m, uint32_t addr, uint16_t *word);
int32_t emu_memory_read_dword(struct emu_memory *m, uint32_t addr, uint32_t *dword);
int32_t emu_memory_read_block(struct emu_memory *m, uint32_t addr, void *dest, size_t len);
int32_t emu_memory_read_string(struct emu_memory *m, uint32_t addr, struct emu_string *s, uint32_t maxsize);

/* write access */
int32_t emu_memory_write_byte(struct emu_memory *m, uint32_t addr, uint8_t byte);
int32_t emu_memory_write_word(struct emu_memory *m, uint32_t addr, uint16_t word);
int32_t emu_memory_write_dword(struct emu_memory *m, uint32_t addr, uint32_t dword);
int32_t emu_memory_write_block(struct emu_memory *m, uint32_t addr, void *src, size_t len);

/* segment selection */
void emu_memory_segment_select(struct emu_memory *m, enum emu_segment s);
enum emu_segment emu_memory_segment_get(struct emu_memory *m);

/* information */
uint32_t emu_memory_get_usage(struct emu_memory *m);


#define MEM_BYTE_READ(cpu_p, addr, data_p) \
 { int32_t ret = emu_memory_read_byte((cpu_p)->mem, addr, data_p); \
 if( ret != 0 ) \
  return ret; }

#define MEM_BYTE_WRITE(cpu_p, addr, data) \
 { int32_t ret = emu_memory_write_byte((cpu_p)->mem, addr, data); \
 if( ret != 0 ) \
  return ret; }

#define MEM_WORD_READ(cpu_p, addr, data_p) \
 { int32_t ret = emu_memory_read_word((cpu_p)->mem, addr, data_p); \
 if( ret != 0 ) \
  return ret; }

#define MEM_WORD_WRITE(cpu_p, addr, data) \
 { int32_t ret = emu_memory_write_word((cpu_p)->mem, addr, data); \
 if( ret != 0 ) \
  return ret; }

#define MEM_DWORD_READ(cpu_p, addr, data_p) \
 { int32_t ret = emu_memory_read_dword((cpu_p)->mem, addr, data_p); \
 if( ret != 0 ) \
  return ret; }

#define MEM_DWORD_WRITE(cpu_p, addr, data) \
 { int32_t ret = emu_memory_write_dword((cpu_p)->mem, addr, data); \
 if( ret != 0 ) \
  return ret; }


#endif // HAVE_EMU_MEMORY_H
