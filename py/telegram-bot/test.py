import asyncio
import time
async def f1():
    print("f1")
    await asyncio.sleep(5)
    print("f1 again")

async def f2():
    print("f2")
    await asyncio.sleep(5)
    print("f2 again")

async def main():
    task1 = asyncio.create_task(f1())
    task2 = asyncio.create_task(f2())
    await task1
    await task2

asyncio.run(main())

