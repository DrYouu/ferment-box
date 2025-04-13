MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
    RAM (xrw)  : ORIGIN = 0x20000000, LENGTH = 64K
}

SECTIONS
{
    .text :
    {
        *(.vectors)
        *(.text*)
        *(.rodata*)
        _etext = .;
    } > FLASH

    .data : AT (_etext)
    {
        _data = .;
        *(.data*)
        _edata = .;
    } > RAM

    .bss :
    {
        _bss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
    } > RAM
}
