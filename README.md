# Music Control device

<!-- Tech tags: C, pi pico / rp2040, KiCad ? -->

_A physical device to control my music so I can avoid using macros that dont work while some applications are open_

STATUS: In-Progress

<!-- INTIAL DESIGN (3d render) HERE -->

## description

An embedded systems project that lets me control my music and playlists without the use of macros on my normal peripherals. This project was inspired but the look of an open HDD drive and a record player.

## features

- USB connection
- Full music & playlist control:
  - song display
  - volume control
  - fast-forward / rewind
  - prev / next song
  - song/playlist control
- 3d printed enclosure

## File tree

    ~/
    ├── CMakeLists.txt
    ├── README.md
    ├── assets/
    |   └── ?
    ├── main.c
    └── pico_sdk_import.cmake

## Part list

| Part                | Quantity | Details    | Purpose               |
| ------------------- | -------- | ---------- | --------------------- |
| Pi Pico 2 W         | 1        | RP2040     | main board            |
| LED screen          | 1        | 0.91 inch  | song/playlist display |
| Slide potentiometer | 1        |            | volume control        |
| Rotary encoder      | 1        | Optical    | fast-forward/rewind   |
| Rotary encoder      | 1        | Mechanical | song/playlist control |
| Potentiometer       | 1        |            | on/off switch         |

## Contact

Contact me at: [sparrows.au@gmail.com](mailto:sparrows.au@gmail.com)

See my Github: [github.com/sparrowsaurora](https://github.com/sparrowsaurora)

[(Back to Top)](#music-control-device)
