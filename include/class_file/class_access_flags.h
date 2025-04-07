#ifndef CLASS_ACCESS_FLAGS_H
#define CLASS_ACCESS_FLAGS_H

enum ClassAccessFlag
{
  CLASS_ACC_PUBLIC = 0x0001,
  CLASS_ACC_FINAL = 0x0010,
  CLASS_ACC_SUPER = 0x0020,
  CLASS_ACC_INTERFACE = 0x0200,
  CLASS_ACC_ABSTRACT = 0x0400,
  CLASS_ACC_SYNTHETIC = 0x1000,
  CLASS_ACC_ANNOTATION = 0x2000,
  CLASS_ACC_ENUM = 0x4000
};

#endif // CLASS_ACCESS_FLAGS_H
