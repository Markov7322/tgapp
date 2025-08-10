# TeleTools

Qt Widgets application written in C++ that provides several helper tools for Telegram work:

- **Collect Posts** – gathers links to channel posts that have comments.
- **Collect Contacts** – loads a list of post URLs and extracts unique commenters.
- **Dispatch / Invite** – sends messages or invites to users with basic rate limiting and logging.

The current implementation contains placeholder logic; integrate Telegram through TDLib or another library as needed.

## Build

```bash
cmake -S . -B build && cmake --build build
```

Run the resulting binary `TeleTools` from the `build` directory.
