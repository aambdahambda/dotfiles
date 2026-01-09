#!/usr/bin/python3

import os
import subprocess
import asyncio

from telethon.sync import TelegramClient 

SESSION:  str = os.path.expanduser("~/.telethon-tg-session")
FILE:     str = "/tmp/telegram"

def get_telegram_api_credentials(entry_name: str) -> tuple[str, str]:
	result = subprocess.run(
		[ "pass", "show", entry_name ],
		capture_output = True,
		text=True,
		check=True,
	)
	full_text = result.stdout
	api_id    = full_text.splitlines()[0]
	api_hash  = full_text.splitlines()[1]
	
	return api_id, api_hash

async def monitor(session: str, api_id: int, api_hash: str, file: str) -> None:
	while True:
		unread_dialogs:  int = 0
		unread_messages: int = 0

		async with TelegramClient(session, api_id, api_hash) as client:
			async for dialog in client.iter_dialogs():
				if duc := dialog.unread_count > 0:
					unread_dialogs  += 1
					unread_messages += duc

		with open(FILE, "w") as f:
			output: str = ""
			if unread_dialogs > 0:
				output = f" [#{unread_dialogs}:{unread_messages}]"
			f.write(output)
		
		await asyncio.sleep(10)

async def main(session: str, file: str) -> None:
	credentials = get_telegram_api_credentials("telegram-api/@aambdahambda")
	api_id  : str = credentials[0]
	api_hash: str = credentials[1]

	await monitor(session, api_id, api_hash, file)

if __name__ == "__main__":
	asyncio.run(main(SESSION, FILE))
