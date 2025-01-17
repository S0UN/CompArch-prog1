import java.util.List;

public class LinkedList {
    private static class ListNode {
        int value;
        ListNode next;

        ListNode(int value) {
            this.value = value;
            this.next = null;
        }
    }

    private ListNode head;

    public LinkedList() {
        this.head = null;
    }

    void add(int value) {
        ListNode newNode = new ListNode(value);

        if (this.head == null) {
            this.head = newNode;
            return;
        }

        ListNode current = this.head;

        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    public void fibonacci(int value) {
        if (value <= 0) {
            System.out.println("The number of Fibonacci terms must be positive.");
            return;
        }
    
        this.head = new ListNode(0); 
        if (value == 1) return; 
    
        ListNode current = new ListNode(1);
        this.head.next = current;
    
        int first = 0, second = 1; 
    
        for (int i = 2; i < value; i++) {
            int nextFib = first + second;
            current.next = new ListNode(nextFib); 
            current = current.next; 
            first = second; 
            second = nextFib; 
        }
    }
    

    void prepend(int value) {
        ListNode newNode = new ListNode(value);
        newNode.next = this.head;
        this.head = newNode;
    }

    void print() {
        ListNode current = this.head;
        while (current != null) {
            System.out.print(current.value + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }

    void delete(int value) {
        while (this.head != null && this.head.value == value) {
            this.head = this.head.next;
        }

        if (this.head == null) {
            return;
        }

        ListNode current = this.head;
        while (current.next != null) {
            if (current.next.value == value) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
    }

    int size() {
        int count = 0;
        ListNode current = this.head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    public int get(int index) {
        if (index < 0 || index >= this.size()) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + this.size());
        }
        ListNode current = this.head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        return current.value;
    }

    public void set(int index, int value) {
        if (index < 0 || index >= this.size()) {
            throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + this.size());
        }
        ListNode current = this.head;
        for (int i = 0; i < index; i++) {
            current = current.next;
        }
        current.value = value;
    }

    void insertAt(int index, int value) {
        if (index < 0) {
            throw new IndexOutOfBoundsException("Index cannot be negative.");
        }

        ListNode newNode = new ListNode(value);
        if (index == 0) {
            newNode.next = this.head;
            this.head = newNode;
            return;
        }

        ListNode current = this.head;
        for (int i = 0; current != null && i < index - 1; i++) {
            current = current.next;
        }

        if (current == null) {
            throw new IndexOutOfBoundsException("Index is out of bounds.");
        }

        newNode.next = current.next;
        current.next = newNode;
    }
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
    
        // add Test
        list.add(10);
        list.add(20);
        list.add(30);
        System.out.print("add Test: ");
        list.print();
    
        // Prepend Test
        list.prepend(5);
        System.out.print("Prepend Test: ");
        list.print();
    
        // Size Test
        System.out.println("Size Test: " + list.size());
    
        // Get Test
        try {
            System.out.println("Get Test (index 1): " + list.get(1));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    
        // Set Test
        try {
            list.set(1, 15);
            System.out.print("Set Test (set index 1 to 15): ");
            list.print();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    
        // Insert At Test
        try {
            list.insertAt(2, 25);
            System.out.print("Insert At Test (insert 25 at index 2): ");
            list.print();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    
        // Delete Test
        list.delete(30);
        System.out.print("Delete Test (delete 30): ");
        list.print();
    
        // Fibonacci Test
        LinkedList fibList = new LinkedList();
        fibList.fibonacci(8);
        System.out.print("Fibonacci Test: ");
        fibList.print();
    }
    
}
