import threading

# Shared resource
shared_resource = 0

# Create a mutex
mutex = threading.Lock()

# Function to increment the shared resource
def increment():
    global shared_resource
    mutex.acquire()
    shared_resource += 1
    mutex.release()

# Create multiple threads
threads = []
for _ in range(5):
    t = threading.Thread(target=increment)
    threads.append(t)

# Start the threads
for t in threads:
    t.start()

# Wait for all threads to finish
for t in threads:
    t.join()

# Print the final value of the shared resource
print(shared_resource)
