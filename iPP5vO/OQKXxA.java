import java.lang.ref.*;

class MyObject {
    private String data;

    public MyObject(String data) {
        this.data = data;
    }

    public String getData() {
        return data;
    }
}

class MemoryManagementExample {
    public static void main(String[] args) {
        MyObject strongReference = new MyObject("Strong Reference");

        WeakReference<MyObject> weakReference = new WeakReference<>(strongReference);
      
        SoftReference<MyObject> softReference = new SoftReference<>(strongReference);

        ReferenceQueue<MyObject> referenceQueue = new ReferenceQueue<>();
        PhantomReference<MyObject> phantomReference = new PhantomReference<>(strongReference, referenceQueue);

        strongReference = null;

        System.out.println("Weak Reference: " + weakReference.get());
        System.out.println("Soft Reference: " + softReference.get());
        System.out.println("Phantom Reference: " + phantomReference.get());

        System.gc();

        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("After Garbage Collection:");
        System.out.println("Weak Reference: " + weakReference.get());
        System.out.println("Soft Reference: " + softReference.get());
        System.out.println("Phantom Reference: " + phantomReference.get());
    }
}
