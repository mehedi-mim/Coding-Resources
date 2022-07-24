import time
import logging
import asyncio
from aiohttp import ClientSession, ClientResponseError

logging.getLogger().setLevel(logging.INFO)

async def fetch(session, url):
    try:
        async with session.get(url, timeout=15) as response:
            resp = await response.read()
    except ClientResponseError as e:
        logging.warning(e.code)
    except asyncio.TimeoutError:
        logging.warning("Timeout")
    except Exception as e:
        logging.warning(e)
    else:
        return resp
    return


async def fetch_async(loop, r):
    # please use url by your choice
    url = "*** some image url ****"
    tasks = []
    # try to use one client session
    async with ClientSession() as session:
        for i in range(r):
            task = asyncio.ensure_future(fetch(session, url))
            tasks.append(task)
        # await response outside the for loop
        responses = await asyncio.gather(*tasks)
    return responses


if __name__ == '__main__':
    for ntimes in [1, 10, 100, 500, 1000]:
        start_time = time.time()
        loop = asyncio.get_event_loop()
        future = asyncio.ensure_future(fetch_async(loop, ntimes))
        loop.run_until_complete(future)
        responses = future.result()
        logging.info('Fetch %s urls takes %s seconds', ntimes, str(time.time() - start_time))
        logging.info('{} urls were read successfully'.format(len(responses)))
