
//! @brief 
//! 先使用 long 后使用 char 是为了最大化利用寄存器的宽度进行拷贝
//! 使用 unsigned 是避免转换成其他类型时发生符号扩展，
//! 并且跨平台兼容: 大多数平台的 char 是默认 signed，ARM 是默认 unsigned
//! 
void* my_memcpy(void* des, const void* src, unsigned int n_bytes) {
  unsigned long* d = (unsigned long*)des;
  const unsigned long* s = (const unsigned long*)src;
  while (n_bytes >= sizeof(unsigned long)) {
    *d++ = *s++;
    n_bytes -= sizeof(unsigned long);
  }

  if (n_bytes > 0) {
    unsigned char* dd = (unsigned char*)des;
    const unsigned char* ss = (const unsigned char*)src;
    while (n_bytes--) {
      *dd++ = *ss++;
    }
  }

  return des;
}

//! @brief 
//! 这里主要是提供 从后往前 / 从前往后 两种复制途径
//!
void* my_memmove(void* des, const void* src, unsigned int n_bytes) {
  if (des == src) 
    return;

  unsigned char* d = (unsigned char*)des;
  const unsigned char* s = (const unsigned char*)src;

  if (d < s) {
    for (int i = 0; i < n_bytes; ++i) {
      d[i] = s[i];
    }
  } else {
    for (int i = n_bytes - 1; i >= 0; --i) {
      d[i] = s[i];
    }
  }

  return des;
}

